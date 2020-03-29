#include<iostream>
#include<stack>

using namespace std;

stack<int> st;

void convert_to_bin(int dec,int total_digits)
{
  while(dec>0)
    {
      st.push(dec%2);
      dec=dec/2;
    }
  while(st.size()<total_digits)
    {
      st.push(0);
    }
}

void print_bin()
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
  convert_to_bin(dec,total_digits);
  print_bin();
  return 0;
}
