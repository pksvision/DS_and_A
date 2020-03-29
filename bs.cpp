#include<iostream>
#include<vector>

using namespace std;

std::vector<int > array;

bool bins(int left, int right, int value)
{
	if(left<=right)
	{
		int mid=(left+right)/2;
		if(array[mid]==value)
		{
			cout<<"Left : "<<left<<" Right : "<<right<<" Array[mid] : "<<array[mid]<<endl;
			return true;
		}
		else if(array[mid]>value)
		{
			cout<<"Left : "<<left<<" Right : "<<right<<" Array[mid] : "<<array[mid]<<endl;
			return bins(left, mid-1,value);
		}
		else if(array[mid]<value)
		{
			cout<<"Left : "<<left<<" Right : "<<right<<" Array[mid] : "<<array[mid]<<endl;
			return bins(mid+1, right, value);
		}
	}
	return false;
}

int main(int argc, char * argv[])
{
	cout<<"Enter the size of the array"<<endl;
	int n;
	cin>>n;
	int val;
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		array.push_back(val);
	}
	cout<<"Enter the value to be search in the array"<<endl;
	int s;
	cin>>s;
	if(bins(0,array.size()-1,s))
		cout<<"Value found"<<endl;
	else cout<<"Value not found"<<endl;
	return 0;
}