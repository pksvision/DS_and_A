#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

struct Node 
{
	int data;
	struct Node * next;
};

struct Node * root=NULL;

typedef pair<string,string> node_pair;

std::vector<struct Node *> linked_list;

std::vector<node_pair> node_pair_list;

std::vector<int> nodes_in_loop;

struct Node *  createNode(int value)
{
	struct Node * nptr=(struct Node *)malloc(sizeof(struct Node));
	nptr->data=value;
	nptr->next=NULL;
	return nptr;
}

void insert(struct Node * nptr)
{
	linked_list.push_back(nptr);
}

void add_next(int index,int pos)
{
	if(pos<1)
		linked_list[index]->next=NULL;
	else	
		linked_list[index]->next=linked_list[pos-1];	
}

void print_list()
{
	for(int i=0;i<linked_list.size();i++)
	{
		cout<<linked_list[i]->data<<"   ";
		if(linked_list[i]->next)
			cout<<linked_list[i]->next->data<<endl;
		else
			cout<<"NULL"<<endl;
	}
}

bool detect_loop()
{
	if(linked_list[linked_list.size()-1]->next==NULL)
		return false;
	for(int i=0;i<linked_list.size();i++)
	{
				if(linked_list[linked_list.size()-1]->next==linked_list[i])
				{
					for(int m=i;m<linked_list.size();m++)
						nodes_in_loop.push_back(linked_list[m]->data);
					return true;
				}
	}
	return false;
}

void remove_loop()
{
	linked_list[linked_list.size()-1]->next=NULL;
}

int main(int argc, char * argv[])
{
	string token;
	string line;
	string np[2];
	int r=0;
	ifstream my_file("data.txt");
	if(my_file.is_open())
	{
		while(getline(my_file,line))
		{
			istringstream iss(line);
			while(getline(iss,token,' '))
			{
				int i=0;
				while(token[i]!='\0')
				{
					np[r].push_back(token[i]);
					i++;
				}
				r++;				
			}		
			r=0;
			node_pair_list.push_back(make_pair(np[0],np[1]));
			np[0].clear();
			np[1].clear();				
		}
		if(node_pair_list.size()>0)
		{
			struct Node * nptr;
			//cout<<"Readed file is "<<endl;
			//for(int i=0;i<node_pair_list.size();i++)
			//cout<<"'"<<node_pair_list[i].first<<"'  '"<<node_pair_list[i].second<<"'"<<endl;
			for(int i=0;i<node_pair_list.size();i++)
			{
				nptr=createNode(stoi(node_pair_list[i].first));
				insert(nptr);						
			}
			for(int i=0;i<node_pair_list.size();i++)
			{
				add_next(i,stoi(node_pair_list[i].second));			
			}
			cout<<"Linked Lists is "<<endl;
			print_list();
			if(detect_loop())
			{
				cout<<"Loop present"<<endl;
				cout<<"Nodes in the loop are "<<endl;
				for(int i=0;i<nodes_in_loop.size();i++)
					cout<<nodes_in_loop[i]<<" ";
				cout<<endl;
				remove_loop();
				cout<<"New Linked List is "<<endl;
				print_list();
			}
			else
				cout<<"Loop not present"<<endl;
		}
		else
			cout<<"Empty File"<<endl;
	}
	else
		cout<<"File not found"<<endl;
	return 0;
}