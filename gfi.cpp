#include<iostream>
#include<fstream>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
using namespace std;

int main(int argc, char * argv[])
{
	struct stat st={0};
	if(stat(argv[1],&st)<0)
		cout<<"File Error "<<endl;
	else
	{
		cout<<"File attributes are : "<<st.st_mode<<endl;
	}
	return 0;
}