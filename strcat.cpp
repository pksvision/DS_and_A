#include<iostream>

using namespace std;

string my_strcat(string s1, string s2)
{
	int len2=s2.length();
	int i=0;
	while(i<len2)
	{
		s1.push_back(s2[i]);
		i++;
	}
	return s1;
}

int main(int argc, char * argv[])
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	cout<<my_strcat(s1,s2)<<endl;
	return 0;
}
