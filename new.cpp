#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char * argv[])
{
	string f;
	cout<<"Enter a file name"<<endl;
	cin>>f;
	ofstream file;
	file.open(f.c_str(),std::ios_base::app);
	if(file.is_open())
	{
		file<<"New contents are this 1234";
	}
	else
		cout<<"No file"<<endl;
	return 0;
}