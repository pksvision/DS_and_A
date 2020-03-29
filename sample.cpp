#include<iostream>
#include<string.h>

using namespace std;

int main(int argc, char * argv[])
{
	char a1[10];
	cin>>a1;
	char a2[10];
	strcpy(a2,a1);
	cout<<"a1 "<<a1<<" a2 "<<a2<<endl;
	strcpy(a2,"wel");
	cout<<"a1 "<<a1<<" a2 '"<<a2<<"'"<<endl;
	return 0;
}