#include<iostream>

using namespace std;

/*s1: welcome
  s2: Delhi
  start1:1
  length:4
  start2:3
  finalS:Delelcohi */

string merged_copy(string s1, string s2, int start1, int length1, int start2)
{
	string s;
	int i=0;
	while(i<start2)
	{
		s.push_back(s2[i]);
		i++;
	}
	i=start1;
	while(i<=length1)
	{
		s.push_back(s1[i]);
		i++;
	}
	i=start2;
	while(i<s2.length())
	{
		s.push_back(s2[i]);
		i++;
	}
	return s;
}

int main(int argc, char* argv[])
{
	string s1;
	string s2;
	int start1, length1, start2;
	cout<<"Enter string 1"<<endl;
	getline(cin,s1);
	cout<<"Enter string 2"<<endl;
	getline(cin,s2);
	cout<<"Enter start1"<<endl;
	cin>>start1;
	cout<<"Enter length1"<<endl;
	cin>>length1;
	cout<<"Enter start2"<<endl;
	cin>>start2;
	cout<<merged_copy(s1,s2,start1,length1,start2)<<endl;
	return 0;
}
