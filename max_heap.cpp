#include<iostream>
#include<vector>

using namespace std;

std::vector<int> elements;
struct PriorityQueue
{
  int left(int i)
  {
    return 2*i+1;
  }

  int right(int i)
  {
    return (2*i+2);
  }

  int parent(int i)
  {
    return (i-1)/2;
  }

  void max_heapify(int i)
  {
    int largest;
    int l=left(i);
    int r=right(i);
    if((l<elements.size())&&(elements[l]>elements[i]))
      largest=l;
    else largest=i;
    if((r<elements.size()) && (elements[r]>elements[largest]))
      largest=r;
    if(largest!=i)
      {
       swap(largest,i);
       max_heapify(largest);
      }
  }

  void swap(int a, int b)
  {
    int temp;
    temp=elements[a];
    elements[a]=elements[b];
    elements[b]=temp;
  }

  void push(int key)
  {
    elements.push_back(key);
    int heap_size=elements.size();
    for(int i=(heap_size)/2;i>=0;i--)
      max_heapify(i);
  }

  void print_queue()
  {
    for(int i=0;i<elements.size();i++)
    {
      cout<<elements[i]<<" ";
    }
  }

  int pop()
  {
    if(elements.size()<1)
      {
        cout<<"\nHeap underflow\n";
	return 0;
      }
    int max=elements[0];
    elements[0]=elements[elements.size()-1];
    elements.pop_back();
    max_heapify(0);
    return max;
  }

  int top()
  {
    if(elements.size()<1)
      {
	cout<<"\nHeap underflow\n";
	return 0;
      }
    int top=elements[0];
    return top;
  }

  int size()
  {
    return elements.size();
  }

  bool empty()
  {
    if(elements.size()==0)
      return true;
    else
      return false;
  }

  void increase_key(int i, int key)
  {
    if(key<elements[i])
      cout<<"Proposed key is already smaller than present value"<<endl;
    else
      {
	elements[i]=key;
	while((i>=0)&&(elements[parent(i)]<elements[i]))
	  {
	    swap(i,parent(i));
	    i=parent(i);
	  }
      }
  }

  void decrease_key(int i, int key)
  {
    if(key>elements[i])
      cout<<"Proposed key is greater than present key. Invalid"<<endl;
    else
      {
	elements[i]=key;
        max_heapify(i);
      }
  }
};

int main(int argc, char* argv[])
{
  PriorityQueue pq;
  int value,option,index;
  cout<<"Enter an option\n1-push\n2-pop\n3-top\n4-print\n5-size\n6-empty\n7-sort\n8-increase key\n9-decrease key\n10-quit"<<endl;
  cin>>option;
  while(option!=10)
    {
      switch(option)
	{
          case 1: cout<<"Enter a value"<<endl;
	          cin>>value;
	          pq.push(value);
	          break;

	  case 2: cout<<"\nPopped value from the Max heap is \n "<<pq.pop();
	          break;

	  case 3: cout<<"\nTop most element in the Max heap is\n"<<pq.top();
	          break;

	  case 4: cout<<"\nContents of the max heap are \n";
	          pq.print_queue();
	          break;

	  case 5: cout<<"\nSize of the max heap is \n"<<pq.size();
	          break;

	  case 6: (pq.empty()==true)?cout<<"\nheap is empty\n":cout<<"\nHeap is not empty\n";
	          break;

	  case 7: cout<<"\nSorted contents are\n";
	          while(!pq.empty())
                     cout<<pq.pop()<<" ";
	          break;
	  case 8: cout<<"\nEnter index and proposed new greater value\n";
	          cin>>index;
		  cin>>value;
		  pq.increase_key(index,value);
	          break;

	  case 9: cout<<"\nEnter index and proposed new smaller value\n";
	          cin>>index;
		  cin>>value;
		  pq.decrease_key(index,value);
	          break; 
	}
      cout<<"Enter an option\n1-push\n2-pop\n3-top\n4-print\n5-size\n6-empty\n7-sort\n8-increase key\n9-decrease key\n10-quit"<<endl;
      cin>>option;
    }
   
}
