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
  int i=0;
  int intexp;
  while(i<exp_tokens.size())
    {
      if(exp_tokens[i].compare("+")==0)
	{
	  b=st.top();
	  st.pop();
	  a=st.top();
	  st.pop();
	  c=a +b;
	  st.push(c);
	}
      else  if(exp_tokens[i].compare("-")==0)
	{
	  b=st.top();
	  st.pop();
	  a=st.top();
	  st.pop();
	  c=a -b;
	  st.push(c);
	}
      else if(exp_tokens[i].compare("*")==0)
	{
	  b=st.top();
	  st.pop();
	  a=st.top();
	  st.pop();
	  c=a *b;
	  st.push(c);
	}
      else if(exp_tokens[i].compare("/")==0)
	{
	  b=st.top();
	  st.pop();
	  a=st.top();
	  st.pop();
	  c=a /b;
	  st.push(c);
	}
      else if(exp_tokens[i].compare("^")==0)
	{
	  b=st.top();
	  st.pop();
	  a=st.top();
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
      i++;
    }
  cout<<"The result is "<<st.top()<<endl;
  st.pop();
}

int main(int argc, char * argv[])
{
  cout<<"Enter a post fix expression"<<endl;
  string exp;
  getline(cin,exp);
  eval(exp);
  return 0;
}
