#include<iostream>

using namespace std;

int power(int base, int expo)
{
  int res=1;
  for(int i=0;i<expo;i++)
    res=res*base;

  return res;
}

int sum(int num, int expo)
{
  int res=0;
  int d;
  while(num>0)
    {
      d=num%10;
      res=res+power(d,expo);
      num=num/10;
    }
  return res;
}

int digits(int num)
{
  int digi=0;
  while(num>0)
    {
      num=num/10;
      digi++;
    }
  return digi;
}

int main(int argc, char * argv[])
{
  int num=stoi(argv[1]);
  int digi=digits(num);
  //cout<<"Digits "<<digi<<endl;
  if(sum(num,digi)==num)
    cout<<"Armstrong number"<<endl;
  else
    cout<<"Not an armstrong number"<<endl;
  return 0;
}
