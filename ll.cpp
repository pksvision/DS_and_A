#include<iostream>

using namespace std;

struct Node
{
  int data;
  struct Node * next;
};

struct Node * root=NULL;
int total=0;

struct Node * createNode(int value)
{
  struct Node * np=(struct Node *)malloc(sizeof(struct Node));
  np->data=value;
  np->next=NULL;
  return np;
}

struct Node * addToList(struct Node * nptr, int pos)
{
  if(pos>total+1 || pos<1)
    {
      cout<<"Invalid Position. Could not add the node."<<endl;
      return root;
    }
  else
    {
      if(total==0)
	{
	  root=nptr;
	  total++;
	  cout<<"Node added."<<endl;
	  return root;
	}
      else
	{
	  int count=1;
	  struct Node * p=root, *q=NULL;
	  while(p!=NULL && count!=pos)
	    {
	      q=p;
	      p=p->next;
	      count++;
	    }
	  nptr->next=p;
	  if(p==root)
	    root=nptr;
	  if(q)
	    q->next=nptr;
	  total++;
	  cout<<"Node added."<<endl;
	  return root;
	}
    }
}

struct Node * deleteFromList(int value)
{
  if(root!=NULL)
    {
      struct Node * nptr=root;
      if(nptr->data==value)
	{
	  root=nptr->next;
	  free(nptr);
	  total--;
	  cout<<"Node deleted."<<endl;
	  return root;
	}
      else
	{
	  struct Node * p=NULL;
	  while(nptr->data!=value)
	    {
	      p=nptr;
	      nptr=nptr->next;
	    }
	  struct Node * q=nptr->next;
	  p->next=q;
	  free(nptr);
	  total--;
	  cout<<"Node deleted."<<endl;
	  return root;
	}
    }
  else
    {
      cout<<"List is empty. Nothing to delete"<<endl;
      return root;
    }
}

void printList()
{
  if(root==NULL)
    cout<<"List is empty"<<endl;
  else
    {
      struct Node * p=root;
      cout<<"Contents of the lists are "<<endl;
      while(p)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
      cout<<endl;
    }
}

int main(int argc, char * argv[])
{
  cout<<"Enter an option\n1-insert\n2-delete\n3-print\n4-exit"<<endl;
  int opt;
  cin>>opt;
  int val,pos;
  struct Node * np;
  while(opt!=4)
    {
      switch(opt)
	{
	   case 1: cout<<"Enter a value to be added in the list"<<endl;
	           cin>>val;
	           cout<<"Enter the position"<<endl;
		   cin>>pos;
		   np=createNode(val);
		   root=addToList(np,pos);
		   break;
	   case 2: cout<<"Enter a value to be deleted from the list"<<endl;
	           cin>>val;
	           root=deleteFromList(val);
		   break;
	   case 3: printList();
	           break;
	}
      cout<<"Enter an option\n1-insert\n2-delete\n3-print\n4-exit"<<endl;
      cin>>opt;
    }
  return 0;
}
