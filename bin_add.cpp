#include<iostream>
#include<stack>

using namespace std;

stack<int> carry;
stack <string> sum;
stack<int> pad;

void pad_zeros(int digits)
{
      int count=digits-1-sum.size();
      //cout<<"Count = "<<count<<endl;
      while(count!=0)
	{
	  pad.push(0);
	  // cout<<pad.top()<<" pushed into pad stack"<<endl;
	  count--;
	}
}

void print_res(string bin1, string bin2)
{
  cout<<"Addtion of "<<bin1<<" and "<<bin2<<" is ";
  if(pad.size()!=0)
    {
      while(pad.size()!=0)
	{
	  cout<<pad.top();
	  pad.pop();
	}
    }
   if(carry.size()!=0)
    {
      cout<<carry.top();
      carry.pop();
    }
  while(sum.size()!=0)
    {
      cout<<sum.top();
      sum.pop();
    }
  cout<<endl;
}

void bin_addition(string bin1, string bin2)
{
  int len1=bin1.length();
  int len2=bin2.length();
  int prev_carry;
  carry.push(0);
  while(len1!=0 && len2!=0)
    {
      if(carry.size()!=0)
	{
              prev_carry=carry.top();
              carry.pop();
        }
      if((bin1[len1-1]=='0') && (bin2[len2-1]=='0'))
	{
               if(prev_carry==1)
		 {
                   sum.push("1");
		 }
               else
		 {
		  sum.push("0");
		 }
	        carry.push(0);
		//cout<<sum.top()<<" pushed into stack"<<endl;
	}
      if((bin1[len1-1]=='0') && (bin2[len2-1]=='1'))
	{
               if(prev_carry==1)
		 {
                   sum.push("0");
                   carry.push(1);
                 }
               else
		 {
		   sum.push("1");
		   carry.push(0);
		 }
	       //cout<<sum.top()<<" pushed into stack"<<endl;
	}
      if((bin1[len1-1]=='1') && (bin2[len2-1]=='0'))
	{
               if(prev_carry==1)
		   {
                      sum.push("0");
                      carry.push(1);
                   }
               else
		 {
		   sum.push("1");
		   carry.push(0);
		 }
	       //cout<<sum.top()<<" pushed into stack"<<endl; 
	}
      if((bin1[len1-1]=='1') && (bin2[len2-1]=='1'))
	{
                if(prev_carry==1)
		  {
                      sum.push("1");
                      carry.push(1);
                  }
		else
		  {
		     sum.push("0");
                     carry.push(1);
                  }
		//	cout<<sum.top()<<" pushed into stack"<<endl;
	}
      len1--;
      len2--;
    }
 if(len1!=0)
   {
     //cout<<"bin 2 "<<bin2<<" finished: value of len1 "<<len1<<" with carry "<<carry.top()<<endl;
     while(len1!=0)
       {
	 if(carry.size()!=0)
	 {
              prev_carry=carry.top();
              carry.pop();
         }
	 if((bin1[len1-1]=='0') && (prev_carry==0))
	   {
	     sum.push("0");
	     carry.push(0);
	   }
	 if((bin1[len1-1]=='0') && (prev_carry==1))
	   {
	     sum.push("1");
	     carry.push(0);
	   }
	 if((bin1[len1-1]=='1') && (prev_carry==0))
	   {
	     sum.push("1");
	     carry.push(0);
	   }
	 if((bin1[len1-1]=='1') && (prev_carry==1))
	   {
	     sum.push("0");
	     carry.push(1);
	   }
	 len1--;
	 //cout<<sum.top()<<" pushed into stack"<<endl;
       }
   }
 else if (len2!=0)
   {
     //cout<<"bin 1 "<<bin1<<" finished: value of len2 "<<len2<<" with carry "<<carry.top()<<endl;
       while(len2!=0)
       {
	 if(carry.size()!=0)
	 {
              prev_carry=carry.top();
              carry.pop();
         }
	 if((bin2[len2-1]=='0') && (prev_carry==0))
	   {
	     sum.push("0");
	     carry.push(0);
	   }
	 if((bin1[len2-1]=='0') && (prev_carry==1))
	   {
	     sum.push("1");
	     carry.push(0);
	   }
	 if((bin1[len2-1]=='1') && (prev_carry==0))
	   {
	     sum.push("1");
	     carry.push(0);
	   }
	 if((bin1[len2-1]=='1') && (prev_carry==1))
	   {
	     sum.push("0");
	     carry.push(1);
	   }
	 len2--;
	 //cout<<sum.top()<<" pushed into stack"<<endl;
       }
   }
}

int main(int argc, char * argv[])
{
  string bin1=argv[1];
  string bin2=argv[2];
  int digits=stoi(argv[3]);
  if(bin1.length()>digits || bin2.length()>digits)
    {
      cout<<"Buffer Overflow. Number provided needs more space than available"<<endl;
    }
  else
    {
      bin_addition(bin1,bin2);
      if(digits>=(1+sum.size()))
	{
	  pad_zeros(digits);
	  print_res(bin1,bin2);
	}
      else
	cout<<"Arithmetic Overflow"<<endl;
    }
  return 0;
}
