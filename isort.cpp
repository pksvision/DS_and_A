#include<iostream>
#include<vector>

using namespace std;

std::vector<int> array;

void isort()
{
	int temp;
	for(int i=1;i<array.size();i++)
	{
		for(int j=i;j>0;j--)
		{
			if(array[j]<array[j-1])
			{
				temp=array[j];
				array[j]=array[j-1];
				array[j-1]=temp;
			}
			else
				break;
		}
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
	isort();
	cout<<"Sorted elements are "<<endl;
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}
