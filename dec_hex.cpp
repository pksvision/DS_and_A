#include<iostream>
#include<stack>
#include<map>
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

void convert_to_hex(int dec,int total_digits)
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
}

void print_hex()
{
  while(!st.empty())
    {
      cout<<st.top();
      st.pop();
    }
  cout<<endl;
}

int main(int argc, char * argv[])
{
  int dec=stoi(argv[1]);
  int total_digits=stoi(argv[2]);
  INITIALIZE();
  convert_to_hex(dec,total_digits);
  print_hex();
  return 0;
}
