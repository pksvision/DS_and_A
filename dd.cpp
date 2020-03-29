#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

int main(int argc, char * argv[])
{
	cout<<"Enter a path"<<endl;
	string path;
	cin>>path;
	struct stat st={0};
	if(stat(path.c_str(), &st)<0)
		cout<<"Error directory"<<endl;
	else
		rmdir(path.c_str());
	return 0;
}