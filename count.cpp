#include<iostream>

using namespace std;

int words(string s)
{
  int w=0,i=0;
  char prev='\0', curr=s[i];
  while(curr!='\0')
    {
      prev=curr;
      i++;
      curr=s[i];
      if((curr==' ' || curr=='.' || curr==',' || curr=='\0') && (prev!=' ' && prev!='.' && prev!=','))
	w++;
    }
  return w;
}

int chars(string s)
{
  int c=0,i=0;
  while(s[i]!='\0')
    {
      if(s[i]!=',' && s[i]!='.')
	c++;
      i++;
    }
  return c;
}

int dots(string s)
{
  int d=0;
  int i=0;
  while(s[i]!='\0')
    {
      if(s[i]=='.')
	d++;
      i++;
    }
  return d;
}

int spaces(string s)
{
  int sp=0;
  int i=0;
  while(s[i]!='\0')
    {
      if(s[i]==' ')
	sp++;
      i++;
    }
  return sp;
}

int digits(string s)
{
  int d=0;
  int i=0;
  while(s[i]!='\0')
    {
      if(s[i]>='0' && s[i]<='9')
	d++;
      i++;
    }
  return d;
}

int special_chars(string s)
{
  int sc=0;
  int i=0;
  while(s[i]!='\0')
    {
      if(!((s[i]>='A'&& s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')))
	sc++;
      i++;
    }
  return sc;
}

int main(int argc, char * argv[])
{
  cout<<"Enter a text"<<endl;
  string s;
  getline(cin, s);
  cout<<"Enter an option\n1-Words\n2-Chars\n3-Dots\n4-Spaces\n5-Digits\n6-Special Chars\n7-Exit"<<endl;
  int opt;
  cin>>opt;
  while(opt!=7)
    {
      switch(opt)
	{
	  case 1:cout<<"Number of words are "<<words(s)<<endl;
	         break;
	  case 2:cout<<"Number of chars are "<<chars(s)<<endl;
	         break;
	  case 3:cout<<"Number of Dots are "<<dots(s)<<endl;
	         break;
	  case 4:cout<<"Number of Spaces are "<<spaces(s)<<endl;
	         break;
	  case 5:cout<<"Number of Digits are "<<digits(s)<<endl;
	         break;
	  case 6:cout<<"Number of Special Chars are "<<special_chars(s)<<endl;
	         break;
	}
      cout<<"Enter an option\n1-Words\n2-Chars\n3-Dots\n4-Spaces\n5-Digits\n6-Special Chars\n7-Exit"<<endl;
  cin>>opt;
    }
  return 0;
}
