#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<limits>

using namespace std;


int INF= std::numeric_limits<int>::max();

int vertices;
int edges;


std::vector<std::vector<int>> dist;
std::vector<bool> visited;
std::vector<int> pi;

std::vector<string> edgeLists;

std::vector<std::vector<int>> adjacencyMatrix;

void INITIALIZE()
{
  for(int i=0;i<vertices;i++)
    {
      dist.push_back(std::vector<int>());
      for(int j=0;j<vertices;j++)
	dist[i].push_back(adjacencyMatrix[i][j]);
    }
}

void flyodwarshall()
{
  INITIALIZE();  
  for(int k=0;k<vertices;k++)
    {
      for(int i=0;i<vertices;i++)
	{
	  for(int j=0;j<vertices;j++)
	    {
	      if((dist[i][k]+dist[k][j] < dist[i][j]) && (dist[i][k]!=INF) && (dist[k][j]!=INF))
		dist[i][j] = dist[i][k] + dist[k][j];
	    }
	}
    }
}

void print_result()
{
  for(int i=0;i<vertices;i++)
    {
      for(int j=0;j<vertices;j++)
	{
	  if(dist[i][j]==INF)
	    cout<<"INF ";
	  else
	    cout<<dist[i][j]<<" ";
	}
      cout<<endl;
    }
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
	    {
	      if(j==i)
		adjacencyMatrix[i].push_back(0);
	      else
		adjacencyMatrix[i].push_back(INF);
	    }
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
	      if(adjacencyMatrix[i][j]==INF)
		cout<<"INF ";
	      else
	       cout<<adjacencyMatrix[i][j]<<" ";
	    }
	  cout<<endl;
	}

      flyodwarshall();
      print_result();
      myfile.close();
    }
  else
    cout<<"Input file does not exists"<<endl;
  return 0;
}
