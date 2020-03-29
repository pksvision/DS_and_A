#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

std::vector<string> size_and_array;

std::vector<int> numbers;

int sum_prev(int i)
{
	int sum=0;
	for(int j=0;j<=i;j++)
		sum=sum+numbers[j];
	return sum;
}

int sum_next(int i)
{
	int sum=0;
	for(int j=i;j<numbers.size();j++)
		sum=sum+numbers[j];
	return sum;
}

int main(int argc, char * argv[])
{
	bool sum_found=false;
	int count=0;
	int testcases;
	string token;
	string line;
	ifstream file("data.txt");
	if(file.is_open())
	{
		while(getline(file,line))
		{
			if(count==0)
			{
				testcases=stoi(line);
				count++;
			}
			else
			{
				size_and_array.push_back(line);
			}
		}
		int j;
		for(int i=0;i<size_and_array.size();i=i+2)
		{
			j=i+1;
			istringstream iss(size_and_array[j]);
			while(getline(iss,token,' '))
				numbers.push_back(stoi(token));
			if(numbers.size()==0)
				cout<<"Invalid sequence"<<endl;
			else if(numbers.size()>=2)
			{
				for(int i=1;i<numbers.size()-1;i++)
				{
					if(sum_prev(i-1)==sum_next(i+1))
					{
						sum_found=true;
						cout<<i+1<<endl;
						break;
					}
				}
				if(sum_found==false)
					cout<<"-1"<<endl;
				sum_found=false;
			}
			else
				cout<<"1"<<endl;
			numbers.clear();
		}
	}
	else
		cout<<"File not found"<<endl;
	return 0;
}