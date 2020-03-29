#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstring>
#include<vector>
#include<math.h>
using namespace std;


long int mul(int n)
{
	int tot=1;
	for(int i=n;i>0;i--)
		tot=tot*i;
	return tot;
}

int main(int argc, char* argv[])
{
	string line;
	std::vector<string> edgesList;
	ifstream myfile(argv[1]);
	int i=0;
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			edgesList.push_back(line);
		}
	}
	cout<<"Data given is "<<endl;
	for(int i=0;i<edgesList.size();i++)
		cout<<edgesList[i]<<endl;

	int s;
	int d;
	int vertices=stoi(edgesList[0]);
	int edges=stoi(edgesList[1]);

	std::vector<std::vector <int> > adjacencyMatrix;
	for(int i=0;i<vertices;i++)
	{
    	adjacencyMatrix.push_back(std::vector<int>());
    	for(int j=0;j<vertices;j++)
    	{    
        	adjacencyMatrix[i].push_back(0);    
    	}	
	}
	
	string token;
	int sd[2], r=0;
	for(int i=2;i<edgesList.size();i++)
	{
		istringstream iss(edgesList[i]);
		while(getline(iss,token,' '))
		{
			sd[r]=stoi(token);
			r++;
		}
		r=0;
		//cout<<sd[0]<<" "<<sd[1]<<endl;
		adjacencyMatrix[sd[0]][sd[1]]=1;
		adjacencyMatrix[sd[1]][sd[0]]=1;
	}

	cout<<"\n"<<"Adjacency Matrix of the graph is "<<endl;
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			cout<<adjacencyMatrix[i][j]<<" ";
		}
		cout<<endl;
	}

	std::vector<std::vector<int>> sets;

	int ver[vertices];
	for(int i=0;i<vertices;i++)ver[i]=i;
	int powSetSize=pow(2,vertices);
	int counter, j,l=0;
	for(counter=1;counter<powSetSize;counter++)
	{
		sets.push_back(std::vector<int>());
		for(j=0;j<vertices;j++)
		{
			if(counter & (1<<j))
			{
				sets[l].push_back(ver[j]);
			}
		}
		l++;
	}
	long int num_edges=0;
	int count=0;
	int res=0;
	std::vector<std::vector<int>> finalCG;
	
	for(int i=0;i<sets.size();i++)//for each set
	{
		if(sets[i].size()>2)// if set size is  > 2
		{
			num_edges=mul(sets[i].size())/(mul(sets[i].size()-2)*2);// find no of edges of complete graph by set[i]
			for(int p=0;p<sets[i].size();p++)
			{
				for(int j=0;j<sets[i].size(),j!=p;j++)
				{
					if(adjacencyMatrix[sets[i][p]][sets[i][j]]==1)
					{
						count++;
					}
				}
			}
			if(count==num_edges)
			{
				finalCG.push_back(sets[i]);
			}
			count=0;
		}
	}
	int max=0;
	for(int i=0;i<finalCG.size();i++)
	{
		if(max<finalCG[i].size())
			max=finalCG[i].size();
	}
	cout<<"\nLength of the maximum clique is "<<max<<endl;
	cout<<"Below are the Cliques computed of length >= 3 "<<endl;

	for( int i=0 ;i<finalCG.size();i++)
	{
		for(int j=0;j<finalCG[i].size();j++)
			cout<<finalCG[i][j]<<" ";
		cout<<endl;
	}



	return 0;
}
