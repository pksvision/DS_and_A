#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;


int main(int argc, char * argv[])
{
	struct stat st={0};
	cout<<"Enter a directory name with path : source"<<endl;
	string src;
	cin>>src;
	cout<<"Enter a new directoryname with path : destination"<<endl;
	string dest;
	cin>>dest;
	if(stat(src.c_str(),&st)<0)
		cout<<"Error DIR: "<<endl;
	else
	{
	  rename(src.c_str(),dest.c_str());
	  cout<<"Directory moved"<<endl;
	}
	return 0;
}