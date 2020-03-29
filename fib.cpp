#include<iostream>

using namespace std;

int fib(int n)
{
  if(n==0)return 0;
  if(n==1) return 1;
  else
   return fib(n-1)+fib(n-2);
}

int main(int argc, char * argv[])
{
  cout<<"Nth fib number is "<<fib(stoi(argv[1]))<<endl;
  return 0;
}
