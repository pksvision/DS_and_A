#include<iostream>

using namespace std;

int check_palindrome(string s)
{
  int res=0;
  string temp;
  temp=s;
  int i=0;
  char ch;
  int last=temp.length()-1;
  while(i<=last)
    {
      ch=temp[i];
      temp[i]=temp[last];
      temp[last]=ch;
      last--;
      i++;
    }
  for(int j=0;j<s.length();j++)
    {
      if( int( tolower(temp[j]) ) != int( tolower(s[j]) )  )
	{
	  res=1;
	  break;
	}
    }
  return res;
}

int main(int argc, char *argv[])
{
  string s;
  cout<<"Enter a string"<<endl;
  cin>>s;
  (check_palindrome(s)==0)?cout<<"\nPalindrome":cout<<"\nNot a palindrome";
  return 0;
}
