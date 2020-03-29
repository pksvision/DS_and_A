#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

std::vector<char> array;

struct Node
{
	char data;
	struct Node * next;
};

struct Node * root=NULL;

struct Node * last=NULL;

struct Node * createNode(char  value)
{
	struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->data=value;
	ptr->next=NULL;	
	return ptr;
}

int total=0;

void insert(struct Node * ptr)
{
	if(root==NULL)
	{
		root=ptr;
		last=ptr;
	}
	else
	{
		last->next=ptr;
		last=ptr;
	}
	total++;
}

void print_list()
{
	struct Node * p=root;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void seperate()
{
	//b a e f g h i u k
	struct Node * p;
	char temp;
	for(int i=1;i<array.size();i++)
	{
		for(int j=i;j>0;j--)
		{
			if((array[j]=='a' || array[j]=='e' || array[j]=='o' || array[j]=='i' || array[j]=='u') && (array[j-1]!='a' && array[j-1]!='e' && array[j-1]!='o' && array[j-1]!='i' && array[j-1]!='u'))
			{
				temp=array[j-1];
				array[j-1]=array[j];
				array[j]=temp;
			}
			else 
				break;
		}
	}
	p=root;
	int i=0;
	while(p)
	{
		p->data=array[i];
		i++;
		p=p->next;
	}
}

int main(int argc, char * argv[])
{
	string line;
	ifstream file("data.txt");
	if(file.is_open())
	{
		while(getline(file,line))
		{
			array.push_back(line[0]);
		}
		struct Node * p;
		for(int i=0;i<array.size();i++)
		{
			p=createNode(array[i]);
			insert(p);
		}
		cout<<"Content of the lists are "<<endl;
		print_list();
		seperate();
		cout<<"Seperated List is "<<endl;
		print_list();
	}
	else
		cout<<"File not found "<<endl;
	return 0;
}