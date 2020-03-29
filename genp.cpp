#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
  int num1,num2;
  cout<<"Enter the numbers";
  cin>>num1>>num2;
  int count=0;
  for(int j=num1;j<=num2;j++)
    {
      for(int i=1;i<=j;i++)
	{
	  if(j%i==0)count++;
	}
      if(count==2)cout<<j<<" ";
      count=0;
    }
  return 0;
}
