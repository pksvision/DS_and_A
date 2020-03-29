#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int INF=std::numeric_limits<int>::max();

std::vector<int> array;

void merge(int l, int q, int r)
{
  int n1=q-l+1;
  int n2=r-(q+1)+1;
  int L[n1+1], R[n2+1];
  for(int i=0;i<n1;i++)
    L[i]=array[l+i];
  for(int j=0;j<n2;j++)
    R[j]=array[q+j+1];
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

void merge_sort(int l, int r)
{
  if(l<r)
    {
      int q=(l+r)/2;
      merge_sort(l,q);
      merge_sort(q+1,r);
      merge(l,q,r);
    }
}


int main(int argc, char * argv[])
{
  int n,val;
  cout<<"Enter the number of elements\n";
  cin>>n;
  cout<<"\nEnter the elements\n";
  for(int i=0;i<n;i++)
    {
       cin>>val;
       array.push_back(val);
    }
  merge_sort(0,array.size()-1);
  for(int i=0;i<array.size();i++)
    cout<<array[i]<<" ";
  return 0;
}
