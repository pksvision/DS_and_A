#include<iostream>

using namespace std;

string rev(string s)
{
	int len=s.length();
	int i=0;
	char temp;
	int j=len-1;
	while(i<=j)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
		i++;
		j--;
	}
	return s;
}

int main(int argc, char* argv[])
{
	string s;
	getline(cin,s);
	cout<<rev(s)<<endl;
	return 0;
}
