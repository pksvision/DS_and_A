#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string s1,s2;

std::vector<std::vector<int>> table;

int max(int a, int b)
{
  return (a>b)?a:b;
}

void find_lcs(string x, string y, int m, int n)
{
  for(int i=0;i<m+1;i++)
    {
      for(int j=0;j<n+1;j++)
	{
	  if(i==0 || j==0)
	    table[i][j]=0;
	  else if (x[i-1]==y[j-1])
	    {
	      table[i][j]=1+table[i-1][j-1];
	    }

	  else
	    table[i][j]=max(table[i-1][j],table[i][j-1]);
	}
    }
  
  for(int i=0;i<m+1;i++)
    {
      for(int j=0;j<n+1;j++)
	{
	  cout<<table[i][j]<<" ";
	}
      cout<<endl;
    }
  
  int index=table[m][n];//last value
  char lcs[index+1];
  lcs[index]='\0';
  int p=m,q=n;
  index--;
  while((p>0) && (q>0))
    {
      if(x[p-1]==y[q-1])
	{
	  lcs[index]=x[p-1];
	  p--;q--;index--;
	}
      else if(table[p-1][q]>table[p][q-1])
	p--;
      else
	q--;
    }
  cout<<"LCS of "<<x<<" and "<<y<<" is "<<lcs<<endl;
}

int length_lcs(string x, string y, int m, int n)
{
  if((m==0) || (n==0))
    return 0;
  
  if(x[m-1]==y[n-1])
    return 1+ length_lcs(x,y,m-1,n-1);

    else return max(length_lcs(x,y,m-1,n),length_lcs(x,y,m,n-1));
}

void init_table()
{
  for(int i=0;i<s1.length()+1;i++)
    {
      table.push_back(std::vector<int>());
      for(int j=0;j<s2.length()+1;j++)
	{
	  table[i].push_back(0);
	}
    }
}

int main(int argc, char*argv[])
{
  s1=argv[1];
  s2=argv[2];
  init_table();
  cout<<"Length of LCS is "<<length_lcs(s1,s2,s1.length(),s2.length())<<endl;
  find_lcs(s1,s2,s1.length(),s2.length());
  return 0;
}
