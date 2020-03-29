#include<iostream>

using namespace std;

class Stack
{

public:
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

  void push(int value)
  {
    struct Node * nptr=createNode(value);
    if(total==0)
      {
	root=nptr;
	total++;
	cout<<"Inserted into Stack."<<endl;
      }
    else
      {
	struct Node * p=root;
	while(p->next!=NULL)
	  {
	    p=p->next;
	  }
	p->next=nptr;
	total++;
	cout<<"Inserted into Stack."<<endl;
      }
  }

  void pop()
  {
    if(root!=NULL)
      {
	struct Node * p=root;
	struct Node * q=NULL;
	while(p->next!=NULL)
	  {
	    q=p;
	    p=p->next;
	  }
	if(q==NULL)
	  root=NULL;
	else
	  {
	    q->next=NULL;
	  }
	free(p);
	cout<<"Value popped."<<endl;
	total--;
      }
    else
      {
	cout<<"Stack is empty. Nothing to pop out"<<endl;
      }
  }

  int top()
  {
    if(total!=0)
      {
	struct Node * p=root;
	while(p->next!=NULL)
	  {
	    p=p->next;
	  }
	return p->data;
      }
    else
      {
	cout<<"Stack is empty. Returning a default value 0."<<endl;
	return 0;
      }
  }

  bool empty()
  {
    return (total==0)?true:false;
  }

  int size()
  {
    return total;
  }
  
  void print()
  {
    if(total==0)
      cout<<"Stack is empty"<<endl;
    else
      {
	struct Node * p=root;
	cout<<"Contents of the Stack are "<<endl;
	while(p)
	  {
	    cout<<p->data<<" ";
	    p=p->next;
	  }
	cout<<endl;
      }
  }
  
};

int main(int argc, char * argv[])
{
  cout<<"Enter an option\n1-push\n2-pop\n3-top\n4-empty?\n5-size\n6-print"<<endl;
  int opt;
  cin>>opt;
  int val;
  Stack obj;
  while(opt!=7)
    {
      switch(opt)
	{
	   case 1: cout<<"Enter a value to be added in the Stack"<<endl;
	           cin>>val;
		   obj.push(val);
		   break;
	   case 2: obj.pop();
		   break;
	   case 3: cout<<"Top value of the stack is "<<obj.top()<<endl;
	           break;
	   case 4: if(obj.empty())
		     cout<<"Stack is empty."<<endl;
		   else
		     cout<<"Stack is not empty."<<endl;
	           break;
	   case 5: cout<<"Size of the Stack is "<<obj.size()<<endl;
	           break;
	   case 6: obj.print();
	           break;
	}
      cout<<"Enter an option\n1-push\n2-pop\n3-top\n4-empty?\n5-size\n6-print"<<endl;
      cin>>opt;
    }
  return 0;
}
