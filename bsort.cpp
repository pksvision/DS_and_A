#include<iostream>
#include<vector>

using namespace std;

std::vector<int> array;

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bsort()
{
	bool swapped=false;
	for(int i=0;i<array.size();i++)
	{
		for(int j=0;j<array.size()-1;j++)
		{
			if(array[j]>array[j+1])
			{
				swap(&array[j],&array[j+1]);
				swapped=true;
			}
		}
		if(swapped==false)
			break;
	}
}

int main(int argc, char * argv[])
{
	cout<<"Enter the number of elements"<<endl;
	int n,val;
	cin>>n;
	cout<<"Enter the elements in the array"<<endl;
	for(int j=0;j<n;j++)
	{
		cin>>val;
		array.push_back(val);
	}
	bsort();
	cout<<"Sorted elements are "<<endl;
	for(int i=0;i<array.size();i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}
