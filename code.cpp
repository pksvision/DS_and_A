#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> p;

std::vector<p> array;

int main() {
	int t,a,b,m,count=0,k=0;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		for(int i=2;i<=b;i++)
		{
			array.push_back(make_pair(i,0));
		}
		while(true)
		{
			m=array[k].first;
			for(int p=k+m;p<array.size();p=p+m)
			{
				if(array[p].second==0)
				{
					array[p].second=1;
					count++;
				}
			}
			if(count==0)
				break;
			k++;
			count=0;
		}
		for(int i=0;i<array.size();i++)
		{
			if(array[i].second==0 && array[i].first >=a)
				printf("%d\n",array[i].first);
		}
		array.clear();
		k=0;
		count=0;
		printf("\n");
	}
	return 0;
}