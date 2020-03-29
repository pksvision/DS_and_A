#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int MAX=std::numeric_limits<int>::max();

std::vector<int> array;

//std::vector<int> kmax;
//std::vector<int> tarray;


void ksmallest(int k)
{
  int ns=array.size();
  int tarray[ns];
  int kmin[k];
  for(int i=0;i<array.size();i++)
    tarray[i]=array[i];
  for(int i=0;i<k;i++)
    kmin[i]=MAX;
  int temp,t;
  for(int i=0;i<ns;i++)
    {
      temp=tarray[i];
      for(int j=0;j<=i;j++)
	{
	  if(kmin[j]>temp)
	    {
	      t=kmin[j];
	      kmin[j]=temp;
	      temp=t;
	    }
	}
    }
  cout<<"Kth smallest without using sorting is "<<kmin[k-1]<<endl;
  //sort(tarray.rbegin(),tarray.rend());
  //cout<<"Kth largest using sorting is "<<tarray[k-1]<<endl;
  //kmax.clear();
  //tarray.clear();
  //kmax.shrink_to_fit();
  //tarray.shrink_to_fit();
  //cout<<"Kmax cp= "<<kmax.size()<<" and tarray= "<<tarray.size()<<endl;
}

int main(int argc, char * argv[])
{
  cout<<"ENter the number of elements"<<endl;
  int n,val;
  cin>>n;
  cout<<"Enter the elements in the array"<<endl;
  for(int i=0;i<n;i++)
    {
      cin>>val;
      array.push_back(val);
    }
  cout<<"Enter the value of K in Kth smallest and enter -1 to exit"<<endl;
  int k;
  cin>>k;
  while(k!=-1)
    {
      ksmallest(k);
      cout<<"Enter the value of K in Kth smallest and enter -1 to exit"<<endl;
      cin>>k;
    }
  return 0;
}
