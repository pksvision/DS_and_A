#include<iostream>
#include<vector>

using namespace std;

std::vector<int> array;

void bsort()
{
	int temp,min,k;
	for(int j=0;j<array.size();j++)
	{
		min=array[j];
		k=j;
		for(int i=j;i<array.size();i++)
		{
			if(min>array[i])
			{
				min=array[i];
				k=i;
			}
		}
		temp=array[k];
		array[k]=array[j];
		array[j]=temp;
	}
}

int main(int argc, char * argv[])
{
	cout<<"Enter the number of elements"<<endl;
	int n,val;
	cin>>n;
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		array.push_back(val);
	}
	bsort();
	cout<<"Sorted elements are "<<endl;
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}