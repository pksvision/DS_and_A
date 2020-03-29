#include<iostream>
#include<vector>

using namespace std;
std::vector<int> array;

int ci()
{
	int iv=0;
	for(int i=0;i<array.size()-1;i++)
	{
		for(int j=i+1;j<array.size();j++)
		{
			if(array[i]>array[j])
				iv++;
		}
	}
	return iv;
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
	cout<<"Total number of inversions are "<<ci()<<endl;
	return 0;
}