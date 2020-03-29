#include<iostream>
#include<limits>

using namespace std;

int INF=std::numeric_limits<int>::max();

struct Node
{
  int data;
  struct Node * prev;
  struct Node * next;
};

struct Node * root=NULL;
int total=0;

struct Node * createNode(int value)
{
  struct Node * np=(struct Node *)malloc(sizeof(struct Node));
  np->data=value;
  np->next=NULL;
  np->prev=NULL;
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
	  if(p)
	    p->prev=nptr;
	  if(p==root)
	    root=nptr;
	  if(q)
	    q->next=nptr;
	  nptr->prev=q;
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
	  if(nptr->next)
	    nptr->next->prev=NULL;
	  free(nptr);
	  total--;
	  cout<<"Node deleted."<<endl;
	  return root;
	}
      else
	{
	  struct Node * p=NULL;
	  while(nptr!=NULL)
	    {
	      if(nptr->data==value)
		break;
	      else
		{
		  p=nptr;
		  nptr=nptr->next;
		}
	    }
	  if(nptr==NULL)
	    {
	      cout<<"Value not found. Can't delete."<<endl;
	      return root;
	    }
	  else
	    {
	      struct Node * q=nptr->next;
	      p->next=q;
	      if(q)
		q->prev=p;
	      free(nptr);
	      total--;
	      cout<<"Node deleted."<<endl;
	      return root;
	    }
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

int get_element(int pos)
{
  struct Node * p=root;
  int count=0;
  while(count!=pos && p!=NULL)
    {
      p=p->next;
      count++;
    }
  return p->data;
}

void set_element(int pos, int val)
{
  struct Node * p=root;
  int count=0;
  while(count!=pos && p!=NULL)
    {
      p=p->next;
      count++;
    }
  p->data=val;
}

void merge(int l, int q, int r)
{
  int n1=q-l+1;
  int n2=r-(q+1)+1;
  int L[n1+1], R[n2+1];
  for(int i=0;i<n1;i++)
    L[i]=get_element(l+i);
  for(int j=0;j<n2;j++)
    R[j]=get_element(q+j+1);
  L[n1]=INF;
  R[n2]=INF;
  int i=0,j=0;
  for(int k=l;k<=r;k++)
    {
      if(L[i]<=R[j])
	{
	  set_element(k,L[i]);
	  i++;
	}
      else
	{
	  set_element(k,R[j]);
	  j++;
	}
    }
}

void mergesort(int left, int right)
{
  if(left< right)
    {
      int mid= (left+right)/2;
      mergesort(left, mid);
      mergesort(mid+1, right);
      merge(left, mid, right);
    }
}

int main(int argc, char * argv[])
{
  cout<<"Enter an option\n1-insert\n2-delete\n3-sort\n4-print\n5-exit"<<endl;
  int opt;
  cin>>opt;
  int val,pos;
  struct Node * np;
  while(opt!=5)
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
	   case 4: printList();
	           break;
	   case 3: if(total>0)
	             mergesort(0,total-1);
		   else
		     cout<<"Empty list. Nothing to sort"<<endl;
	           break;
	}
      cout<<"Enter an option\n1-insert\n2-delete\n3-sort\n4-print\n5-exit"<<endl;
      cin>>opt;
    }
  return 0;
}
