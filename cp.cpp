#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<sys/types.h>
#include<sys/stat.h>

using namespace std;

std::vector<char> chars;
std::vector<string> path;

int main(int argc, char * argv[])
{
	string src;
	cout<<"Enter a file name : source "<<endl;
	cin>>src;

	string dest;
	cout<<"Enter destinaion file name : copied as "<<endl;
	cin>>dest;

	char ch;
	
	ifstream file_src(src.c_str());
	if(file_src.is_open())
	{
	  while(file_src.get(ch))
		chars.push_back(ch);

	  istringstream iss(dest);
	  string token;
	  while(getline(iss,token,'/'))
	    path.push_back(token);

	  
	   struct stat st ={0};
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
	  ofstream myfile(p.c_str());
	  for(int i=0;i<chars.size();i++)
		myfile<<chars[i];
	  myfile.close();	
	}
	else
		cout<<"Source file not exists"<<endl;
	return 0;
}