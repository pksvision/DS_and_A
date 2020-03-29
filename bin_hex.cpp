#include<iostream>
#include<iomanip>
#include<stack>
#include<map>
#include<sstream>
using namespace std;

stack<string> st;
map<int , string> mp;

void INITIALIZE()
{
  mp[10]="A";
  mp[11]="B";
  mp[12]="C";
  mp[13]="D";
  mp[14]="E";
  mp[15]="F";
}

void push_corresponding_value(int val)
{
  st.push(mp[val]);
}

string convert_dec_hex(int dec,int total_digits)
{
  while(dec>0)
    {
      if(dec%16<10)
	st.push(to_string(dec%16));
      else
	push_corresponding_value(dec%16);
      dec=dec/16;
    }
  while(st.size()<total_digits)
    {
      st.push("0");
    }
  stringstream ss;
  while(!st.empty())
    {
      ss<<st.top();
      st.pop();
    }
  return ss.str();
}

int power(int base, int expo)
{
  int res=1;
  while(expo>0)
    {
      res=res*base;
      expo--;
    }
  return res;
}

int convert_bin_dec(int bin)
{
  int res=0;
  int count=0;
  while(bin>0)
    {
      res=res+((bin%10)*power(2,count));
      bin=bin/10;
      count++;
    }
  return res;
}

string convert_bin_hex(int bin, int digits)
{
  INITIALIZE();
  string res;
  int dec_res=convert_bin_dec(bin);
  res=convert_dec_hex(dec_res,digits);
  return res;
}

int main(int argc, char * argv[])
{
  int bin=stoi(argv[1]);
  int digits=stoi(argv[2]);
  cout<<"Hexa value is : "<<convert_bin_hex(bin,digits)<<endl;
}
