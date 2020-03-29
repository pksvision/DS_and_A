#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

/*Declare custom comparator*/
struct compare
{
	bool operator()(pair<string ,int> p1, pair <string,int > p2)
	{
		return p2.second<p1.second;
	}
};

std::set<int> unique_pids;
int vertices;
std::vector<std::vector<int>> adjacencyMatrix;
std::vector<int> visited;
typedef pair<string, int> sdc_pair;
priority_queue<sdc_pair,std::vector<sdc_pair>, compare> pq;//min heap

struct Disjoint_Sets
{
  int *parent, *rank;
  int n;// No of vertices in graph
  Disjoint_Sets(int v)
  {
    n=v;
    parent= new int[v];// assign parent array equal to n+1
    rank= new int[v];
    /*Initially all vertices are in different sets and have rank 0*/
    for(int i=0;i<v;i++)
      {
	rank[i]=0;
	parent[i]=i;
      }
  }
  //find parent of node u
  //path compression
  int find(int u)
  {
    if( u!= parent[u])
      parent[u]=find(parent[u]);
    return parent[u];
  }

  void merge(int x, int y)
  {
    x=find(x);
    y=find(y);

    if(rank[x] > rank[y])
      parent[y]=x;
    else
      parent[x]=y;

    if(rank[x]==rank[y])
      rank[y]++;
  }
};

void kruskal()
{
        long int mst_cost_wt=0;
        cout<<"\nBelow are the in kruskal's MST with "<<vertices<<" vertices\n";
  	Disjoint_Sets ds(vertices);
	int u, v,r=0;
	int sd[2];
	int set_u,set_v;
	string uvLine,token;
	pair<string, int> p;
	while(pq.size()>0)
	{
		p=pq.top();
		uvLine=p.first;
		//cout<<p.first<<" "<<p.second<<endl;
		istringstream iss(uvLine);
		while(getline(iss,token,' '))
		  {
		    sd[r]=stoi(token);
		    r++;
		  }
		r=0;
		u=sd[0];
		v=sd[1];
		set_u= ds.find(u);
		set_v= ds.find(v);
		if(set_u!=set_v)
		  {
		    cout<<u<<" "<<v<<endl;
		    mst_cost_wt=mst_cost_wt+p.second;
		    ds.merge(set_u, set_v);
		  }
		pq.pop();
	}
	for(int i=0;i<vertices;i++)
	{
	 cout<<ds.parent[i]<<" ";
	 unique_pids.insert(ds.parent[i]);
	}
	//cout<<"\nSet size is : "<<unique_pids.size()<<endl;
	if(unique_pids.size()>1)
	  {
	    cout<<"\nNo of Connected Components : "<<unique_pids.size()<<endl;
	  }
	else
	  {
	    cout<<"\nGraph is Connected. MST Cost is : "<<mst_cost_wt<<endl;
	  }
}

int main(int argc, char *argv[])
{
	string line;
	ifstream myfile(argv[1]);
	std::vector<string> edgeLists;
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			edgeLists.push_back(line);
		}
	}
	vertices=stoi(edgeLists[0]);
	int edges=stoi(edgeLists[1]);
	for(int i=0;i<vertices;i++)
	{
		adjacencyMatrix.push_back(std::vector<int>());
		for(int j=0;j<vertices;j++)
		{
			adjacencyMatrix[i].push_back(0);
		}
	}
	int sdc[3],r=0;
	string token;
	string v1,v2,vp;
	stringstream merge,s1,s2;
	cout<<"Size of Edge List : "<<edgeLists.size()<<endl;
	for(int i=2;i<edgeLists.size();i++)
	{
		istringstream iss(edgeLists[i]);
		while(getline(iss,token,' '))
		{
			sdc[r]=stoi(token);
			r++;
		}
		r=0;
		adjacencyMatrix[sdc[0]][sdc[1]]=1;
		adjacencyMatrix[sdc[1]][sdc[0]]=1;
		v1=to_string(sdc[0]);
		v2=to_string(sdc[1]);
		merge<<v1<<" "<<v2;
		cout<<"V1->V2: "<<merge.str()<<" Cost:"<<sdc[2]<<endl;
		pq.push(make_pair(merge.str(),sdc[2]));
		merge.str(string());//clear merge buffer
	}
	cout<<"Given Adjacency Matrix is \n";
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			cout<<adjacencyMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<vertices;i++)
		visited.push_back(0);
	kruskal();
	return 0;
}
