#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<limits>

using namespace std;


int INF= std::numeric_limits<int>::max();

int vertices;
int edges;


std::vector<int> dist;
std::vector<bool> visited;

std::vector<string> edgeLists;

std::vector<std::vector<int>> adjacencyMatrix;

int min_distance()
{
  int min_dis=INF;
  int min_index;
  for(int i=0;i<vertices;i++)
    if((visited[i]==false) && (min_dis>dist[i]))
      min_dis=dist[i], min_index=i;
  return min_index;
}

void dijkstra(int src)
{
  dist[src]=0;

  //SSP for all vertices : counter for all vertices 
  for(int count=0;count<vertices-1;count++)
    {
      //nearest to source which is unexplored till now
      int u=min_distance();
      for(int m=0;m<vertices;m++)
	cout<<dist[m]<<" ";
      cout<<"\nSelected u "<<u<<endl;
      //visit the nearest
      visited[u]=true;
      // Update the distance values of adjacent vertices of u
      for(int i=0;i<vertices;i++)
	{
	  if((visited[i]==false) && (adjacencyMatrix[u][i]>0) && (dist[i] > dist[u]+ adjacencyMatrix[u][i]) && (dist[u]!=INF))
	    {
	      dist[i]=dist[u]+adjacencyMatrix[u][i];
	    }
	}
    }
  
}

void print_result()
{
  cout<<" To      Distance"<<endl<<"-----------------"<<endl;
  for(int i=0;i<vertices;i++)
    cout<<" "<<i<<"          "<<dist[i]<<endl;
}

int main(int argc, char * argv[])
{
  string line;
  ifstream myfile(argv[1]);
  if(myfile.is_open())
    {
      cout<<"Reading graph from the file..."<<endl;
      while(getline(myfile,line))
	edgeLists.push_back(line);
      cout<<"Done reading"<<endl<<"Adjacency Matrix of the graph is"<<endl;
      vertices=stoi(edgeLists[0]);
      edges=stoi(edgeLists[1]);
      for(int i=0;i<vertices;i++)
	{
	  adjacencyMatrix.push_back(std::vector<int>());
	  for(int j=0;j<vertices;j++)
	    adjacencyMatrix[i].push_back(0);
	}
      int sdc[3];
      int r=0;
      string token;
      for(int i=2;i<edgeLists.size();i++)
	{
	  istringstream iss(edgeLists[i]);
	  while(getline(iss,token,' '))
	    {
	      sdc[r]=stoi(token);
	      r++;
	    }
	  r=0;
	  adjacencyMatrix[sdc[0]][sdc[1]]=sdc[2];
	}
      for(int i=0;i<vertices;i++)
	{
	  for(int j=0;j<vertices;j++)
	    {
	      cout<<adjacencyMatrix[i][j]<<" ";
	    }
	  cout<<endl;
	}
      for(int i=0;i<vertices;i++)
	dist.push_back(INF), visited.push_back(false);

      cout<<"Enter the source vertex"<<endl;
      int src;
      cin>>src;
      dijkstra(src);
      cout<<"Calculated Min distance from source vertex "<<src<<" is "<<endl;
      print_result();
      myfile.close();
    }
  else
    cout<<"Input file does not exists"<<endl;
  return 0;
}
