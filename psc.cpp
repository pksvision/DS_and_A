#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char * argv[])
{
  char c;
freopen(argv[1],"r",stdin);
while( ( c=getchar() )!=EOF)
  cout<<c;
  return 0;
}
