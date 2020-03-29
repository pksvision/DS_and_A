#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>

using namespace std;

std::vector<string> sorted_s1;
std::vector<string> sorted_s2;

std::vector<std::vector<char>> subs1;
std::vector<std::vector<char>> subs2;

string s1,s2;


void print_long_common_subs()
{
  string lcs;
  int maxLen=0;

  for(int i=0;i<sorted_s1.size();i++)
    {
      for(int j=0;j<sorted_s2.size();j++)
	{
	  if((sorted_s2[j]==sorted_s1[i]) && (sorted_s2[j].length()>maxLen))
	    {
	      lcs=sorted_s2[j];
	      maxLen=sorted_s2[j].length();
	    }
	}
    }
  cout<<"\nLCS of "<<s1<<" and "<<s2<<" is "<<lcs<<endl;
}

void print_s1_subs()
{
  cout<<"Substring of string "<<s1<<" are\n";
  for(int i=0;i<sorted_s1.size();i++)
    cout<<sorted_s1[i]<<endl;
}

void print_s2_subs()
{
  cout<<"Substrings of string "<<s2<<" are\n";
  for(int i=0;i<sorted_s2.size();i++)
    cout<<sorted_s2[i]<<endl;
}

void sort_s1()
{
  sort(sorted_s1.begin(),sorted_s1.end());
}

void merge_s1()
{
  ostringstream merger;
  for(int i=0;i<subs1.size();i++)
    {
      for(int j=0;j<subs1[i].size();j++)
	{
	  merger<<subs1[i][j];
	}
      sorted_s1.push_back(merger.str());
      merger.str(string());
    }
}

void find_subs1(string s)
{
  int m=0;
  for(int i=0;i<s.length();i++)
    {
      for(int j=i;j<s.length();j++)
	{
	  subs1.push_back(std::vector<char>());
	  for(int k=i;k<=j;k++)
	    {
	      subs1[m].push_back(s[k]);
	    }
	  m++;
	}
    }
  cout<<"No of possible substring of string "<<s<<" are "<<subs1.size()<<endl;
}


void sort_s2()
{
  sort(sorted_s2.begin(),sorted_s2.end());
}

void merge_s2()
{
  ostringstream merger;
  for(int i=0;i<subs2.size();i++)
    {
      for(int j=0;j<subs2[i].size();j++)
	{
	  merger<<subs2[i][j];
	}
      sorted_s2.push_back(merger.str());
      merger.str(string());
    }
}

void find_subs2(string s)
{
  int m=0;
  for(int i=0;i<s.length();i++)
    {
      for(int j=i;j<s.length();j++)
	{
	  subs2.push_back(std::vector<char>());
	  for(int k=i;k<=j;k++)
	    {
	      subs2[m].push_back(s[k]);
	    }
	  m++;
	}
    }
  cout<<"No of possible substring of string "<<s<<" are "<<subs2.size()<<endl;
}

int main(int argc, char* argv[])
{
  s1=argv[1];
  s2= argv[2];
  find_subs1(s1);
  find_subs2(s2);
  merge_s1();
  merge_s2();
  sort_s1();
  sort_s2();
  print_s1_subs();
  print_s2_subs();
  print_long_common_subs();
  return 0;
}
