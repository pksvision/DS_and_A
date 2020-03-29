#include<iostream>
#include<limits>


using namespace std;

int INF=std::numeric_limits<int>::max();

int check_pal(string str)
{
  int res=1;
  int i=0, j=str.length()-1;
  while(i<=j)
    {
      if(str[i]!=str[j])
	{
	  res=0;
	  break;
	}
      i++;
      j--;
    }
  return res;
}

void generate_pal(int value)
{
  int i;
  string str;
  int res=0;
  for(i=value+1;i<INF;i++)
    {
      str=to_string(i);
      res=check_pal(str);
      if(res==1)
	break;
    }
  cout<<i<<endl;
}


int main(int argc, char* argv[])
{
  int value;
  cin>>value;
  generate_pal(value);
  return 0;
}
