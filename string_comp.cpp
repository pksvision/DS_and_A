#include<iostream>
#include<string>
#include<vector>

using namespace std;

std::vector<string> strings;

//Res=0 means s1<s2
int comp(string s1, string s2)
{
  int res=0,i=0;
  while((s1[i]!='\0')||(s2[i]!='\0'))
    {
      if( int ( tolower(s1[i]) ) > int ( tolower(s2[i]) ) )
	{
	  res=1;
	  break;
	}
      else if( int ( tolower(s1[i]) ) < int ( tolower(s2[i]) ))
	{
	  res=0;
	  break;
	}
      else
      i++;
    }
  return res;
}

int main(int argc, char *argv[])
{
  string s1;
  cout<<"Enter strings \n";
  cin>>s1;
  strings.push_back(s1);
  while(cin.get()!='\n')
    {
      cin>>s1;
      strings.push_back(s1);
    }

  cout<<"\nUnsorted sequence : ";
  for(int i=0;i<strings.size();i++)
    cout<<strings[i]<<" ";
  cout<<endl;

  //Insertion sort
  string temp; int k;
  for(int i=1;i<strings.size();i++)
    {
      k=i;
      for(int j=i-1;j>=0;j--)
	{
	  if(comp(strings[k],strings[j])==0)//s1<s2
	    {
	      temp=strings[j];
	      strings[j]=strings[k];
	      strings[k]=temp;
	      k=j;
	    }
	  else
	    break;
	}
    }

  cout<<"\nSorted sequence : ";
  for(int i=0;i<strings.size();i++)
    cout<<strings[i]<<" ";
  cout<<endl;
  
  return 0;
}
