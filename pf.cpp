#include<iostream>

using namespace std;

bool is_prime(int num)
{
  bool res=true;
  int count=0;
  for(int i=1;i<=num;i++)
    {
      if(num%i==0)count++;
    }
  return  (count==2)? true:false;
}

int main(int argc, char * argv[])
{
  int num;
  cout<<"Enter a number\n";
  cin>>num;
  for(int i=2;i<=num;i++)
    {
      if(is_prime(i))
	{
	  while((num%i==0) && (num!=1))
	    {
	      num=num/i;
	      cout<<i<<" ";
	    }
	}
    }
  return 0;
}
