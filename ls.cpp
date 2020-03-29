#include<iostream>
#include<vector>

using namespace std;

std::vector<int> array;

int main(int argc, char * argv[])
{
	cout<<"Enter the size of the array"<<endl;
	int n;
	cin>>n;
	int val;
	cout<<"Enter the elements of array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		array.push_back(val);
	}
	cout<<"Enter the element to search in the array"<<endl;
	int s;
	cin>>s;
	bool found=false; int index;
	for(int i=0;i<n;i++)
	{
		if(array[i]==s)
		{
			found=true;
			index=i;
			break;
		}
	}
	(found==true)?cout<<"Element found in the array at "<<index+1<<" position"<<endl:cout<<"Element not found"<<endl;
	return 0;
}