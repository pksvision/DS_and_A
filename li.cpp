#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
  float a1,a2,b1,b2,c1,c2;
  cout<<"Enter line coefficients of two lines in the format of Ax + By = C as A B C\n";
  cin>>a1>>b1>>c1>>a2>>b2>>c2;
  float temp=a2,ta,tb,tc;
  ta=a1;tb=b1;tc=c1;
  a2=a2*a1;
  b2=b2*a1;
  c2=c2*a1;
  a1=a1*temp;
  b1=b1*temp;
  c1=c1*temp;
  float b=b1-b2;
  float c=c1-c2;
  float y=c/b,x;
  x=(tc-y*tb)/ta;
  cout<<"X= "<<x<<" Y= "<<y<<endl;
  return 0;
}
