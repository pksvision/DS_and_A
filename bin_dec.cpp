#include<iostream>
#include<iomanip>
using namespace std;

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

int convert_bin_dec(int bin, int digits)
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

int main(int argc, char * argv[])
{
  int bin=stoi(argv[1]);
  int digits=stoi(argv[2]);
  cout<<"Decimal value is : "<<setfill('0')<<setw(digits)<<convert_bin_dec(bin,digits)<<endl;
}
