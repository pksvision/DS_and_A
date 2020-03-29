#include<iostream>
#include<vector>
#include<limits>
#include<fstream>
#include<sstream>

using namespace std;

int MIN = std::numeric_limits<int>::min();

struct Node
{
	int data;
	bool occupied;
	bool deleted;
};

std::vector<struct Node *> table;

std::vector<int> popped_out_values;

struct Node * createNode(int value)
{
	struct Node * nptr=(struct Node *)malloc(sizeof(struct Node));
	nptr->data=value;
	nptr->occupied=false;
	nptr->deleted=false;
	return nptr;
}

int hash2(int x)
{
	return 5- (x%5);
}

void printTable()
{
	cout<<"Contents of the table are "<<endl;
	for(int i=0;i<table.size();i++)
		if(table[i])
			cout<<table[i]->data<<"        "<<table[i]->occupied<<"             "<<table[i]->deleted<<endl;
		else
			cout<<"NULL          "<<table[i]->occupied<<"          "<<table[i]->deleted<<endl;
}

bool rehash(int index, int value, int probes)
{
	if(table[index]->occupied==false || table[index]->deleted==true)
	{
		table[index]->data=value;
		table[index]->occupied=true;
		table[index]->deleted=false;
		cout<<"Value inserted with "<<probes<<" probes "<<endl;
		return true;
	}
	else if(table[index]->occupied==true && table[index]->data==value)
	{
		cout<<"Can't insert. Already inserted"<<endl;
		return true;	
	}
	else
	    return false;
}

bool insert(int val)
{
	bool inserted=false;
	int index=val%table.size();
	if(table[index]->occupied==false || table[index]->deleted==true)
	{
		table[index]->data=val;
		table[index]->occupied=true;
		inserted=true;
		table[index]->deleted=false;
		cout<<"Value inserted."<<endl;
	}
	else if (table[index]->occupied==true && table[index]->data==val)
	{
		cout<<"Can't insert. Already inserted"<<endl;
		inserted=true;
	}
	else
	{
		int probes=0;
		for(int i=1;i<table.size();i++)
		{
			probes++;
			index=(val+i*hash2(val))%table.size();
			if(rehash(index,val,probes))
			{
				inserted=true;
				break;
			}
		}
	}
	if(!inserted)
		cout<<"Table full. Can't insert"<<endl;
	return inserted;
}

bool search(int value)
{
	int index=value%table.size();
	int prev_index=index-1;
	if(prev_index<0)
		prev_index=table.size()-1;
	while(index!=prev_index && (table[index]->occupied==true || table[index]->deleted==true))
	{
		if(table[index]->data==value)
		{
			return true;
		}
		index++;
		if(index==table.size())
			index=0;
	}
	return false;
}

bool del_probes(int index, int value)
{
	if(index==table.size())
		index=0;
	int prev_index=index-1;
	if(prev_index<0)
		prev_index=table.size()-1;
	while(index!=prev_index && (table[index]->occupied==true || table[index]->deleted==true))
	{
		if(table[index]->data==value)
		{
			table[index]->data=MIN;
			table[index]->occupied=false;
			table[index]->deleted=true;
			cout<<"Value deleted."<<endl;
			return true;		
		}
		index++;
		if(index==table.size())
			index=0;
	}
	return false;
}

void deleteNode(int value)
{
	bool deleted=false;
	int index=value%table.size();
	if(table[index]->data==value)
	{
		table[index]->data=MIN;
		table[index]->occupied=false;
		table[index]->deleted=true;
		deleted=true;
	}
	else
	{
		deleted=del_probes(index+1,value);
	}
	if(!deleted)
		cout<<"Value not found to delete. Invalid value"<<endl;
}

void fill_initial_data()
{
	string opstr[2];
	string line,token;
	int value,p=0;
	ifstream file("data.txt");
	if(file.is_open())
	{
		while(getline(file,line))
		{
			istringstream iss(line);
			while(getline(iss,token,' '))
				opstr[p]=token,p++;
			value=stoi(opstr[1]);
			if(opstr[0].compare("I")==0)
			{
				cout<<"Trying to insert "<<value<<endl;
				if(insert(value)==false)
					popped_out_values.push_back(value);
			}
			else
			{
				cout<<"Trying to Deleting "<<value<<endl;
				if(opstr[0].compare("D")==0)
					deleteNode(value);
			}
			p=0;
		}
	}
	file.close();
	cout<<"Value which cannot be inserted in the table are "<<endl;
	for(int i=0;i<popped_out_values.size();i++)
		cout<<popped_out_values[i]<<endl;
}

int main(int argc, char * argv[])
{
	cout<<"Enter the size of the hash table"<<endl;
	int n;
	cin>>n;
	struct Node * nptr;
	for(int i=0;i<n;i++)
	{
		nptr=createNode(MIN);
		table.push_back(nptr);
	}
	fill_initial_data();
	cout<<"Enter an option\n1-Insert\n2-Delete\n3-Search\n4-Print Table\n5-Exit"<<endl;
	int opt;
	int val;
	cin>>opt;
	while(opt!=5)
	{
		switch(opt)
		{
			case 1: cout<<"Enter a value to be inserted into the table"<<endl;
					cin>>val;
					insert(val);
					break;
			case 2: cout<<"Enter a value to be deleted from the table"<<endl;
					cin>>val;
					deleteNode(val);
					break;
			case 3: cout<<"Enter a value to be searched in the table"<<endl;
					cin>>val;
					if(search(val))
						cout<<"Element found in the hash table"<<endl;
					else
						cout<<"Element not found in the hash table"<<endl;
					break;
			case 4: printTable();
					break;
		}
		cout<<"Enter an option\n1-Insert\n2-Delete\n3-Search\n4-Print Table\n5-Exit"<<endl;
     	cin>>opt;
	}
	return 0;
}