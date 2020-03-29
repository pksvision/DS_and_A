#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

std::vector<std::vector<int>> table;

int max(int a, int b)
{
  return (a>b)?a:b;
}

void INIT(int n)
{
  for(int i=0;i<n+1;i++)
    {
      table.push_back(std::vector<int>());
      for(int j=0;j<n+1;j++)
	table[i].push_back(0);
    }
}

void print_res(string str1, string str2)
{
  cout<<endl;
  for(int i=0;i<str1.length()+1;i++)
    {
      for(int j=0;j<str2.length()+1;j++)
	{
	  if(i==0 || j==0)
	    table[i][j]=0;
	  else if (str1[i-1]==str2[j-1])
	    {
	      table[i][j]=1+table[i-1][j-1];
	    }

	  else
	    table[i][j]=max(table[i-1][j],table[i][j-1]);
	}
    }
    for(int i=0;i<table.size();i++)
    {
      for(int j=0;j<table[i].size();j++)
	{
	  cout<<table[i][j];
	}
      cout<<endl;
    }
  int p=str1.length(), q=str2.length();
  int index= table[p][q];
  char lps[index+1];
  lps[index]='\0';
  index--;
  while(p>0 && q>0)
    {
      if(str1[p-1]==str2[q-1])
	{
	  lps[index]=str1[p-1];
	  p--;
	  q--;
	  index--;
	}
      else if (table[p-1][q]>table[p][q-1])
	p--;
      else
	q--;
    }

  cout<<"\nLPS is : "<<lps<<endl;
}

int find_lps(string str1, string str2, int m, int n)
{
  if(m==0 || n==0)
    {
      return 0;
    }
  if(str1[m-1]==str2[n-1])
    {
      return 1+find_lps(str1,str2,m-1,n-1);
    }
  else
    {
      return max(find_lps(str1,str2,m-1,n), find_lps(str1,str2,m,n-1));
    }
}

int main(int argc, char * argv[])
{
  string str=argv[1];
  INIT(str.length());
  string rev_str(str);
  reverse(rev_str.begin(),rev_str.end());
  cout<<"\nlength of LPS is "<<find_lps(str,rev_str,str.length(),rev_str.length())<<endl;
  print_res(str, rev_str);
  return 0;
}
