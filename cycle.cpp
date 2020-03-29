#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

std::vector<string> edgeLists;
std::vector<std::vector<int>> adjacencyMatrix;
int vertices,edges;

//Define 3 colors
//0- White: vertex is not processed yet: initially all vertices are white
//1- Gray: vertex is being processed: all its descendants have not been explored yet
//2- Black: vertex and all it's descendants have been explored.


std::vector<int> color;

void INITIALIZE()
{
  for(int i=0;i<vertices;i++)
    color.push_back(0);
}

bool DFS(int u)
{
  color[u]=1;
  for(int i=0;i<vertices;i++)
    {
      if(adjacencyMatrix[u][i]==1)
	{
	  if(color[i]==1)return true;
	  if(color[i]==0)
	    {
	      if(DFS(i))return  true;
	    }
	}
    }
  color[u]=2;
  return false;
}

bool is_cyclic()
{
  INITIALIZE();
  for(int i=0;i<vertices;i++)
    {
      if(color[i]==0)
	{
	  if(DFS(i))return true;
	}
    }
  return false;
}

int main(int argc, char * argv[])
{
  cout<<"Reading graph from the file <graph>.txt"<<endl;
  string line;
  ifstream myfile(argv[1]);
  if(myfile.is_open())
    {
      while(getline(myfile, line))
	edgeLists.push_back(line);
      vertices=stoi(edgeLists[0]);
      edges=stoi(edgeLists[1]);

      for(int i=0;i<vertices;i++)
	{
	  adjacencyMatrix.push_back(std::vector<int>());
	  for(int j=0;j<vertices;j++)
	    adjacencyMatrix[i].push_back(0);
	}

      string token;
      int r=0;
      int sd[2];
      for(int i=2;i<edgeLists.size();i++)
	{
	  istringstream iss(edgeLists[i]);
	  while(getline(iss,token,' '))
	    sd[r]=stoi(token),r++;
	  r=0;
	  adjacencyMatrix[sd[0]][sd[1]]=1;
	}

      cout<<"Adjacency Matrix of the graph is "<<endl;
      for(int i=0;i<vertices;i++)
	{
	  for(int j=0;j<vertices;j++)
	    {
	      cout<<adjacencyMatrix[i][j]<<" ";
	    }
	  cout<<endl;
	}
      if(is_cyclic())
	cout<<"Graph contains a cycle"<<endl;
      else
	cout<<"Graph does not contains a cycle"<<endl;
    }
  else
    cout<<"Invalid file input. Or. Corrupted file"<<endl;
  
  return 0;
}
