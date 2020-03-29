#include<iostream>
#include<string>

using namespace std;

string str;

string swap_elements(int i,int j)
{
  char temp;
  temp=str[i];
  str[i]=str[j];
  str[j]=temp;
  return str;
}

string reverse_array(string s,int i,int j)
{
  char temp;
  int k=i+1;
  int last=s.length()-1;
  while(k<=last)
    {
      temp=s[k];
      s[k]=s[last];
      s[last]=temp;
      k++;
      last--;
    }
  return s;
}

void lex_perms(string str)
{
  int x=0,y=0;
  for(int i=0;i<str.length();i++)
    {
      if((int(tolower(str[i])) < int(tolower(str[i+1])) ) && (x<i))
	x=i;
    }
  if(x==0)return;
  for(int i=x+1;i<str.length();i++)
    {
       if((int(tolower(str[x])) < int(tolower(str[i])) ) && (y<i))
	 y=i;
    }
  str= swap_elements(x,y);
  str=reverse_array(str,x,str.length()-1);
  cout<<str<<endl;
  lex_perms(str);
}

int main(int argc, char *argv[])
{
  cout<<"Enter a string\n";
  cin>>str;
  cout<<endl;
  lex_perms(str);
  return 0;
}
