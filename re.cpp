#include<iostream>
#include<vector>
#include<limits>
using namespace std;

std::vector<int> array;

int INF=std::numeric_limits<int>::max();
int MINI= std::numeric_limits<int>::min();

void merge(int l, int q, int r)
{
  int n1=q-l+1;
  int n2=r-(q+1)+1;
  int L[n1+1], R[n2+1];
  for(int i=0;i<n1;i++)
    L[i]=array[l+i];
  for(int j=0;j<n2;j++)
    R[j]=array[q+1+j];
  L[n1]=INF;
  R[n2]=INF;
  int i=0,j=0;
  for(int k=l;k<=r;k++)
    {
      if(L[i]<=R[j])
	{
	  array[k]=L[i];
	  i++;
	}
      else
	{
	  array[k]=R[j];
	  j++;
	}
    }
}

void mergesort(int l, int r)
{
  if(l<r)
    {
      int mid=(l+r)/2;
      mergesort(l,mid);
      mergesort(mid+1,r);
      merge(l,mid,r);
    }
}

void remove_rep_elements()
{
  int max_rep=MINI;
  for(int i=0;i<array.size()-1;i++)
    {
      if(array[i]==array[i+1])
	{
	  if(max_rep<array[i])
	    max_rep=array[i];
	  array.erase(array.begin()+i);
	}
    }
  if(max_rep==MINI)
    cout<<"No repeated elements found."<<endl;
  else
    cout<<"Max repeated elements is "<<max_rep<<endl;
}

int remove_rep()
{
  int max_rep=MINI;
  for(int i=0;i<array.size();i++)
    {
      for(int j=i+1;j<array.size();j++)
	{
	  if(array[i]==array[j])
	    {
	      if(max_rep<array[j])
		max_rep=array[j];
	      array.erase(array.begin()+j);
	    }
	}
    }
  if(max_rep==MINI)
    cout<<"No repeated elements found."<<endl;
  else
    cout<<"Max repeated element is "<<max_rep<<endl;
}

int main(int argc, char * argv[])
{
  cout<<"ENter the number of elements"<<endl;
  int n,val;
  cin>>n;
  cout<<"Enter the elements "<<endl;
  for(int i=0;i<n;i++)
    {
      cin>>val;
      array.push_back(val);
    }
  cout<<"Enter an option\n1-using sorting\n2-without using sorting"<<endl;
  int opt;
  cin>>opt;
  switch(opt)
    {
       case 1: mergesort(0,n-1);
               cout<<"Sorted array is "<<endl;
               for(int i=0;i<n;i++)
                  cout<<array[i]<<" ";
               cout<<endl;
               remove_rep_elements();
               cout<<"Array without rep elements is "<<endl;
               for(int i=0;i<array.size();i++)
                  cout<<array[i]<<" ";
               cout<<endl;
               break;

       case 2: remove_rep();
	       cout<<"Array without repeated elements is "<<endl;
	       for(int i=0;i<array.size();i++)
		 cout<<array[i]<<" ";
	       cout<<endl;
	       break;
    }
    return 0;
}
