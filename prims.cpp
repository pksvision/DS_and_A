#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<limits>
#include<queue>
using namespace std;

std::vector<string> edgeLists;

int INF= std::numeric_limits<int>::max();

int vertices,edges;

std::vector<bool> visited; 
std::vector<int> key;
std::vector<int> pi;

std::vector<std::vector<int>> adjacencyMatrix;

void INITIALIZE(int src)
{
  for(int i=0;i<vertices;i++)
    visited.push_back(false),key.push_back(INF),pi.push_back(-1);

  key[src]=0;
  pi[src]=src;
}

int min_index()
{
  int min=INF, min_ind;
  for(int i=0;i<vertices;i++)
    {
      if((key[i]<min) && (visited[i]==false))
	min=key[i], min_ind=i;
    }
  return min_ind;
}

void prims(int src)
{
  INITIALIZE(src);
 
  for(int count=1;count<=vertices;count++)
    {
      int u=min_index();
      visited[u]=true;
      
      for(int i=0;i<vertices;i++)
	{
	  if((adjacencyMatrix[u][i]>0) && (visited[i]==false) && (adjacencyMatrix[u][i]<key[i]))
	    {
	      key[i]=adjacencyMatrix[u][i];
	      pi[i]=u;
	    }
	}
    }
}

void print_res()
{
  cout<<"From          To         Weight"<<endl<<"-------------------------------"<<endl;
  for(int i=0;i<vertices;i++)
    cout<<pi[i]<<"             "<<i<<"              "<<adjacencyMatrix[pi[i]][i]<<endl;
    
}

int main(int argc, char * argv[])
{
  cout<<"Reading data from the <graph>.txt file"<<endl;
  string line;
  ifstream myfile(argv[1]);
  if(myfile.is_open())
    {
      while(getline(myfile,line))
	{
	  edgeLists.push_back(line);
	}
      vertices=stoi(edgeLists[0]);
      edges=stoi(edgeLists[1]);

      for(int i=0;i<vertices;i++)
	{
	  adjacencyMatrix.push_back(std::vector<int>());
	  for(int j=0;j<vertices;j++)
	    adjacencyMatrix[i].push_back(0);
	}
      
      int sdc[3],r=0;
      string token;
      for(int i=2;i<edgeLists.size();i++)
	{
	  istringstream iss(edgeLists[i]);
	  while(getline(iss,token,' '))
	    {
	      sdc[r]=stoi(token);
	      r++;
	    }
	  adjacencyMatrix[sdc[0]][sdc[1]]=sdc[2];
	  adjacencyMatrix[sdc[1]][sdc[0]]=sdc[2];
	  r=0;
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
      cout<<"Enter a start vertex"<<endl;
      int src;
      cin>>src;
      prims(src);
      print_res();
    }
  else
    cout<<"Invalid input. or . Corrupted input file"<<endl;

  
  return 0;
}
