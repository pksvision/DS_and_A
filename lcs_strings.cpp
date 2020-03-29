#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<set>

using namespace std;

std::vector<std::vector<string>> merged_subs;
typedef std::vector<std::vector<char>> subs;
std::vector<subs> string_subs;
std::vector<string> strings;
std::vector<string> common_strings;
int tot;

void find_lcs()
{
  tot=0;
  string lcs;
  int maxLen=0;
  for(int i=0;i<merged_subs[0].size();i++)//for each sub string in string 0
    {
      tot=0;
      for(int j=1;j<merged_subs.size();j++)
	{
	  if(std::find(merged_subs[j].begin(),merged_subs[j].end(),merged_subs[0][i])!= merged_subs[j].end())
	    {
	      tot++;
	    }
	}
      //cout<<"T val "<<tot;
      if(tot==strings.size()-1)
	{
	  //cout<<merged_subs[0][i]<<endl;
	  common_strings.push_back(merged_subs[0][i]);
	}
    }
  cout<<"Common strings are \n";
  if(common_strings.size()>0)
    {
      for(int i=0;i<common_strings.size();i++)
	cout<<common_strings[i]<<" ";
      int ind=0;
      for(int i=0;i<common_strings.size();i++)
	{
	  if(common_strings[i].length()>maxLen)
	    {
	      ind=i;
	      maxLen=common_strings[i].length();
	    }
	}
      cout<<"\nLongest Common Substring is '"<<common_strings[ind]<<"'"<<endl;
    }
  else
    cout<<"No common Substring present";
}

void print_subs()
{
  for(int i=0;i<merged_subs.size();i++)//for each string
    {
      cout<<"Subs of string "<<strings[i]<<" are "<<endl;
      for(int j=0;j<merged_subs[i].size();j++)
	{
	  cout<<merged_subs[i][j]<<endl;
	}
    }
}

void sort_subs()
{
  for(int i=0;i<merged_subs.size();i++)//for each string
    {
      sort(merged_subs[i].begin(),merged_subs[i].end());
    }
}

void merge_subs()
{
  ostringstream merger;
  int m=0;
  for(int i=0;i<string_subs.size();i++)//for each 2d char array subs
    {
      merged_subs.push_back(std::vector<string>());
      for(int j=0;j<string_subs[i].size();j++)//for each row
	{
	  for(int k=0;k<string_subs[i][j].size();k++)
	    {
	      merger<<string_subs[i][j][k];
	    }
	  merged_subs[m].push_back(merger.str());
	  merger.str(string());
	}
      m++;
    }
}


void find_subs(string s, int index)
{
  int m=0;
  string_subs.push_back(std::vector<std::vector<char>>());
  for(int i=0;i<s.length();i++)
    {
      for(int j=i;j<s.length();j++)
	{
	  string_subs[index].push_back(std::vector<char>());
	  for(int k=i;k<=j;k++)
	    {
	      string_subs[index][m].push_back(s[k]);
	    }
	  m++;
	}
    }
}

int main(int argc, char* argv[])
{
  for(int i=1;i<argc;i++)
    {
      strings.push_back(argv[i]);
      find_subs(argv[i],i-1);
    }
  merge_subs();
  sort_subs();
  print_subs();
  find_lcs();
  return 0;
}
