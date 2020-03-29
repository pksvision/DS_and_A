#include<iostream>
#include<vector>

using namespace std;

//Declare node format

struct Node
{
  int value;
  int left;
  int right;
};

//Declare a vector to store nodes
std::vector<Node> nodes;

void print_tree()
{
  for(int i=0;i<nodes.size();i++)
    cout<<nodes[i].left<<"   "<<nodes[i].value<<"   "<<nodes[i].right<<endl;
}

void insert(int value)
{
  struct Node node;
  node.value=value;
  node.left=-1;
  node.right=-1;
  nodes.push_back(node);
  if(nodes.size()>1)
    {
      int i=0;
      while((i>=0) && (i<nodes.size()))
	{
	  if((nodes[i].value>value) && (nodes[i].left!=-1))
	      i=nodes[i].left;
	  else if ((nodes[i].value<value) && (nodes[i].right!=-1))
	    i=nodes[i].right;
	  else break;
	}
      if((nodes[i].value>value) && (nodes[i].left==-1))
	nodes[i].left=nodes.size()-1;
      else
	nodes[i].right=nodes.size()-1;
    }
}

int main(int argc, char *argv[])
{
  cout<<"Choose one of the options below\n1-Enter a node\n2-Delete a node\n3-Print the tree in L D R format\n4-Quit\n";
  int option;
  cin>>option;
  int val;
  while(option!=4)
    {
      switch(option)
	{
	   case 1: // insert
	     cout<<"Enter the value to be insert\n";
	     cin>>val;
	     insert(val);
	     break;
	   case 2: //Delete
	     break;
	   case 3: //print
	     print_tree();
	     break;
	   case 4: //Quit
	     break;
	   default: //Invalid input
	     break;
	}
      cout<<"Enter an option again\n";
      cin>>option;
    }
  
  return 0;
}
