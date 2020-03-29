#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

std::vector<char> chars;

int main(int argc, char * argv[])
{
	string src;
	cout<<"Enter a file name : source "<<endl;
	cin>>src;
	string dest;
	cout<<"Enter destinaion file name : copied into "<<endl;
	cin>>dest;
	char ch;
	ofstream file_dest;
	ifstream file_src(src.c_str());
	if(file_src.is_open())
	{
		while(file_src.get(ch))
			chars.push_back(ch);

		file_dest.open(dest.c_str(),std::ios_base::app);
		if(file_dest.is_open())
		{
			for(int i=0;i<chars.size();i++)
				file_dest<<chars[i];
			cout<<"Contents copied."<<endl;
		}
		else
			cout<<"Destination file not exists"<<endl;
	}
	else
		cout<<"Source file not exists"<<endl;
	return 0;
}