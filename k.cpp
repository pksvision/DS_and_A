#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> pals;

bool check_pal(string str)
{
  bool res=true;
  int len=str.length(),i=0;
  int j=len-1;
  while(i<=j)
    {
      if(str[i]!=str[j])return false;
      else
	i++,j--;
    }
  return res;
}


int main(int argc, char * argv[])
{
  string str=argv[1];
  string cpy;
  for(int i=0;i<str.length();i++)
    {
      for(int j=i;j<str.length();j++)
	{
	  for(int k=i;k<=j;k++)
	    {
	      cpy+=str[k];
	    }
	  if(check_pal(cpy))
	    pals.push_back(cpy); 
	  cpy="";
	}
    }

  int max_len=1;
  for(int i=0;i<pals.size();i++)
    {
      if(pals[i].length()>=max_len)
	max_len=pals[i].length();
    }

  cout<<"String "<<str<<" is "<<max_len<<" palindrome"<<endl;
  return 0;
}
