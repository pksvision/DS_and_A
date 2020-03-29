#include<iostream>
#include<stack>
#include<cmath>
#include<vector>
#include<sstream>
#include<string>
#include<limits>
using namespace std;

std::stack<int> st;

int MIN= std::numeric_limits<int>::min();
int MAX= std::numeric_limits<int>::max();

void eval(string exp)
{
  // 2 3 1 * + 19 - = -14
  int a,b,c;
  string token;
  istringstream iss(exp);
  std::vector<string> exp_tokens;
  while(getline(iss,token,' '))
    exp_tokens.push_back(token);
  int i=exp_tokens.size()-1;
  int intexp;
  while(i>=0)
    {
      if(exp_tokens[i].compare("+")==0)
	{
	  a=st.top();
	  st.pop();
	  b=st.top();
	  st.pop();
	  c=a +b;
	  st.push(c);
	}
      else  if(exp_tokens[i].compare("-")==0)
	{
	  a=st.top();
	  st.pop();
	  b=st.top();
	  st.pop();
	  c=a -b;
	  st.push(c);
	}
      else if(exp_tokens[i].compare("*")==0)
	{
	  a=st.top();
	  st.pop();
	  b=st.top();
	  st.pop();
	  c=a *b;
	  st.push(c);
	}
      else if(exp_tokens[i].compare("/")==0)
	{
	  a=st.top();
	  st.pop();
	  b=st.top();
	  st.pop();
	  c=a /b;
	  st.push(c);
	}
      else if(exp_tokens[i].compare("^")==0)
	{
	  a=st.top();
	  st.pop();
	  b=st.top();
	  st.pop();
	  c=pow(a,b);
	  st.push(c);
	}
      else
	{
	  intexp=stoi(exp_tokens[i]);
	  if(intexp>=MIN && intexp<=MAX)
	    st.push(intexp);
	}
      i--;
    }
  cout<<"The result is "<<st.top()<<endl;
  st.pop();
}

int main(int argc, char * argv[])
{
  cout<<"Enter a pre fix expression"<<endl;
  string exp;
  getline(cin,exp);
  eval(exp);
  return 0;
}
