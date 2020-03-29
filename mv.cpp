#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<sstream>
#include<vector>

using namespace std;

std::vector<string> path;

int main(int argc, char * argv[])
{
	struct stat st={0};
	cout<<"Enter a file path  source"<<endl;
	string src;
	cin>>src;
	cout<<"Enter a file path destination"<<endl;
	string dest;
	cin>>dest;
	if(stat(src.c_str(),&st)<0)
		cout<<"Error file"<<endl;
	else
	{
	  istringstream iss(src);
	  string token;
	  while(getline(iss,token,'/'))
	    path.push_back(token);
	/*
	  for(int i=0;i<path.size();i++)
	    cout<<"'"<<path[i]<<"'"<<endl;
	*/

	  string cpath="/";
	  stringstream ss;
	  string p;
	  for(int i=0;i<path.size()-1;i++)
	    {
	      if(!(path[i]==""))
		{
		  ss<<cpath<<path[i];
		  p=ss.str();
		  if(stat(p.c_str(),&st)==-1)
		    mkdir(p.c_str(),0700);
		}
	    }
	  ss<<cpath<<path[path.size()-1];
	  p=ss.str();
	  rename(p.c_str(),dest.c_str());
	  cout<<"File moved"<<endl;
	}
	return 0;
}