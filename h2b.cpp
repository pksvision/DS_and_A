#include<iostream>
#include<cmath>
#include<stack>
#include<sstream>
using namespace std;

std::stack<int> st;

int dec(string s)
{
  int d=0;
  int count=0;
  int i=s.length()-1;
  while(i>=0)
    {
        if(s[i]=='A')
	{
	  d=d+10*pow(16,count);
	  count++;
	}
        else
	if(s[i]=='B')
	{
	  d=d+11*pow(16,count);
	  count++;
	}
	else
	if(s[i]=='C')
	{
	  d=d+12*pow(16,count);
	  count++;
	}
	else
	if(s[i]=='D')
	{
	  d=d+13*pow(16,count);
	  count++;
	}
	else
	if(s[i]=='E')
	{
	  d=d+14*pow(16,count);
	  count++;
	}
	else
	if(s[i]=='F')
	{
	  d=d+15*pow(16,count);
	  count++;
	}
	else
	{
	  d=d+(s[i]-'0')*pow(16,count);
	  count++;
	}
      i--;
    }
  return d;
}

string bin(int d)
{
  while(d>0)
    {
      st.push(d%2);
      d=d/2;
    }
  stringstream ss;
  while(!st.empty())
    {
      ss<<to_string(st.top());
      st.pop();
    }
  return ss.str();
}

int main(int argc, char * argv[])
{
  string s;
  cout<<"Enter a Hexa number"<<endl;
  cin>>s;
  cout<<"Decimal value of "<<s<<" is "<<dec(s)<<endl;
  cout<<"Binary value of "<<s<<" is "<<bin(dec(s))<<endl;
  return 0;
}
