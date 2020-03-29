#include<iostream>
#include<fstream>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sstream>
#include<vector>

using namespace std;

std::vector<string> path;
 
int main(int argc, char * argv[])
{
  struct stat st ={0};
  cout<<"Enter a file name with a path to create"<<endl;
  string s;
  cin>>s;
  istringstream iss(s);
  string token;
  while(getline(iss,token,'/'))
    path.push_back(token);

  for(int i=0;i<path.size();i++)
    cout<<"'"<<path[i]<<"'"<<endl;

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
  myfile<<"Welcome to CPP"<<endl;
  myfile.close();
  return 0;
}
