#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

std::vector<int> visited;

std::vector<string> edgeLists;

std::vector<std::vector<int>> adjacencyMatrix;

std::vector<std::vector<int>> temp_adj_matrix;

std::vector<std::vector<int>> comp;
int vertices, edges;
int comp_index=0;

void DFS(int start_vertex)
{
  visited[start_vertex]=1;
  comp[comp_index].push_back(start_vertex);
  for(int i=0;i<vertices-1;i++)
    {
      if((i!=start_vertex) && (visited[i]==0) && (temp_adj_matrix[i][start_vertex]==1))
	{
	  DFS(i);
	}
    }
}

int connected_compos(int v)
{
  int count=0;
  for(int i=0;i<v-1;i++)
    {
      if(visited[i]==0)
	{
	  comp.push_back(std::vector<int>());
	  DFS(i);
	  count++;
	  comp_index++;
	}
    }
  return count;
}

int main(int argc, char *argv[])
{
  string line;
  cout<<"Reading graph from the file..."<<endl;
  ifstream myfile(argv[1]);
  if(myfile.is_open())
    {
      while(getline(myfile,line))
	edgeLists.push_back(line);
    }
  cout<<"Done reading"<<endl;
  vertices=stoi(edgeLists[0]);
  edges=stoi(edgeLists[1]);
 
  for(int i=0;i<vertices;i++)
    {
      adjacencyMatrix.push_back(std::vector<int>());
      for(int j=0;j<vertices;j++)
	{
	  adjacencyMatrix[i].push_back(0);
	}
    }
  
  string edgeline;
  int index=0;
  int sd[2];
  string token;
  for(int i=2;i<edgeLists.size();i++)
    {
      edgeline=edgeLists[i];
      istringstream iss(edgeline);
      while(getline(iss,token,' '))
	{
	  sd[index]=stoi(token);
	  index++;
	}
      adjacencyMatrix[sd[0]][sd[1]]=1;
      adjacencyMatrix[sd[1]][sd[0]]=1;
      index=0;
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

  for(int i=0;i<vertices-1;i++)
    visited.push_back(0);

  //  cout<<"Number of connected componenets  are "<<connected_compos(vertices)<<endl;
  // cout<<"Following are the connected components of the graph"<<endl;
  // for(int i=0;i<comp.size();i++)
  //{
  //  for(int j=0;j<comp[i].size();j++)
  //	{
  //	  cout<<comp[i][j]<<" ";
  //	}
  //  cout<<endl;
  //}

  for(int i=0;i<vertices-1;i++)
    {
      temp_adj_matrix.push_back(std::vector<int>());
      for(int j=0;j<vertices-1;j++)
	{
	  temp_adj_matrix[i].push_back(0);
	}
    }
  int m=0,n=0;
  cout<<"Articulation points are "<<endl;
  for(int i=0;i<vertices;i++)
    {
      for(int j=0;j<vertices;j++)
	{
	  if(j!=i)
	    {
	      for(int k=0;k<vertices;k++)
		{
		  if((k!=i))
		    {
		      temp_adj_matrix[m][n]=adjacencyMatrix[j][k];
		      temp_adj_matrix[n][m]=adjacencyMatrix[k][j];
		      // n++;
		      n++;
		      if(n==vertices-1)
			{
			  n=0;m++;
			}
		    }
		}
	      // m++;
	    }
	}
      if(connected_compos(vertices)>1)
	cout<<i<<" ";
      m=0;n=0;
      temp_adj_matrix.clear();
      visited.clear();
      for(int i=0;i<vertices-1;i++)
	visited.push_back(0);

    }
   return 0;
}
