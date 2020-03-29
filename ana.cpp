#include<iostream>

using namespace std;

void check_ana(string s1, string s2)
{
  int c=0,i;
  for(i=0;i<s1.length();i++)
    {
      for(int j=0;j<s2.length();j++)
	{
	  if(tolower(s1[i])==tolower(s2[j]))
	    {
	      s2[j]=' ';
	      c++;
	      break;
	    }
	}
    }
  if(c==i)
    cout<<"\nAnagrams";
  else
    cout<<"\nNot anagrams";
}

int main(int argc, char * argv[])
{
  string s1,s2;
  cout<<"Enter two strings\n";
  cin>>s1>>s2;
  if(s1.length()!=s2.length())
    cout<<"\nStrings are not anagrams";
  else
    check_ana(s1,s2);
  return 0;
}
