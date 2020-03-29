#include<iostream>

using namespace std;

int main(int argc, char * argv[])
{
  int a=stoi(argv[1]);
  int b=stoi(argv[2]);
  a=a+b;
  b=a-b;
  a=a-b;
  cout<<"swapped: "<<a<<" "<<b<<endl;
  return 0;
}
