#include<iostream>

using namespace std;

int gcd(int n1, int n2)
{
  if((n1==0) && (n2!=0))
    return n2;
  if((n1!=0) && (n2==0))
    return n1;
  else
    return gcd(n2,n1%n2);
}

int main(int argc, char * argv[])
{
  int n1,n2;
  cout<<"Enter two numbers whose GCD has to be found"<<endl;
  cin>>n1>>n2;
  cout<<"\nGCD of "<<n1<<" and "<<n2<<" is "<<gcd(n1,n2)<<endl;
  return 0;
}
