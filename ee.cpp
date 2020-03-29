#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int n1,n2;
  cout<<"Enter two numbers"<<endl;
  cin>>n1>>n2;
  int c,a,x,b,last_b;
  if((n1==0) && (n2==0))
    cout<<"\nGCD of "<<n1<<" and "<<n2<<" is not defined "<<endl;
  else if((n1==0) && (n2!=0))
    cout<<"\nGCD of "<<n1<<" and "<<n2<<" is "<<n2<<endl;
  else if ((n1!=0) && (n2==0))
    cout<<"\nGCD of "<<n1<<" and "<<n2<<" is "<<n1<<endl;
  else
    {
      (n1>n2)?c=n1:c=n2;
      (c==n1)?a=n2:a=n1;
      x=c/a;
      b=c%a;
      last_b=a;
      cout<<"c = "<<c<<" a = "<<a<<" x = "<<x<<" b = "<<b<<endl;
      while(b!=0)
	{
	  c=a;
	  a=b;
	  x=c/a;
	  last_b=b;
	  b=c%a;
	  cout<<"c = "<<c<<" a = "<<a<<" x = "<<x<<" b = "<<b<<endl;
	}
      cout<<"\nGCD of "<<n1<<" and "<<n2<<" is "<<last_b<<endl;
    }
  return 0;
}
