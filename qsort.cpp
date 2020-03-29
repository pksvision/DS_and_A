#include<iostream>
#include<vector>

using namespace std;

std::vector<int> array;

void swap(int i, int j)
{
  int temp=array[i];
  array[i]=array[j];
  array[j]=temp;
}

int partition(int l, int r)
{
  int x= array[r];
  int i= l-1;
  for(int j=l; j<r;j++)
    {
      if(array[j]<=x)
	{
	  i=i+1;
	  swap(i,j);
	}
    }
  swap(i+1,r);
  return i+1;// index of partition element
}


void qsort(int l,int r)
{
  if(l<r)
    {
      int partition_element_index=partition(l,r);
      // cout<<"\nPartition found\n";
      qsort(l,partition_element_index-1);
      qsort(partition_element_index+1,r);
    }
}

int main(int argc, char *argv[])
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
  qsort(0,array.size()-1);
  for(int i=0;i<array.size();i++)
    cout<<array[i]<<" ";
  return 0;
}
