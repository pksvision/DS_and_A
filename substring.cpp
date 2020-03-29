#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<sstream>
#include<algorithm>

using namespace std;

std::vector<std::vector<char>> subs;
std::vector<string> sortedsubs;


int main(int argc, char* argv[])
{
  if(argc>1)
    {
      string orig=argv[1];
    int m=0;
    for(int i=0;i<orig.length();i++)
      {
	for(int j=i;j<orig.length();j++)
	  {
	    subs.push_back(std::vector<char>());
	    for(int k=i;k<=j;k++)
	      {
		subs[m].push_back(orig[k]);
	      }
	    m++;
	  }
      }
    ostringstream merge;
    for(int i=0;i<subs.size();i++)
      {
	for(int j=0;j<subs[i].size();j++)
	  {
	    merge<<subs[i][j];
	  }
	sortedsubs.push_back(merge.str());
	merge.str(string());
      }

    sort(sortedsubs.begin(),sortedsubs.end());
    for(int i=0;i<sortedsubs.size();i++)
      {
	cout<<sortedsubs[i]<<endl; 
      }
  }
  return 0;
}
