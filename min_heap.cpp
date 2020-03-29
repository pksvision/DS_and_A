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

  void min_heapify(int i)
  {
    int smallest;
    int l=left(i);
    int r=right(i);
    if((l<elements.size())&&(elements[l]<elements[i]))
      smallest=l;
    else smallest=i;
    if((r<elements.size()) && (elements[r]<elements[smallest]))
      smallest=r;
    if(smallest!=i)
      {
       swap(smallest,i);
       min_heapify(smallest);
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
      min_heapify(i);
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
    int min=elements[0];
    elements[0]=elements[elements.size()-1];
    elements.pop_back();
    min_heapify(0);
    return min;
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
};


int main(int argc, char* argv[])
{
  PriorityQueue pq;
  int value,option;
  cout<<"Enter an option\n1-push\n2-pop\n3-top\n4-print\n5-size\n6-empty\n7-sort\n8-stop"<<endl;
  cin>>option;
  while(option!=8)
    {
      switch(option)
	{
          case 1: cout<<"Enter a value"<<endl;
	          cin>>value;
	          pq.push(value);
	          break;

	  case 2: cout<<"\nPopped value from the Min heap is \n "<<pq.pop();
	          break;

	  case 3: cout<<"\nTop most element in the Min heap is\n"<<pq.top();
	          break;

	  case 4: cout<<"\nContents of the Min heap are ";
	        pq.print_queue();
	        break;

	  case 5: cout<<"\nSize of the Min heap is "<<pq.size();
	          break;

	  case 6: (pq.empty()==true)?cout<<"\nheap is empty":cout<<"\nHeap is not empty";
	          break;

	case 7:   cout<<"Sorted contents are\n";
	          while(!pq.empty())
                     cout<<pq.pop()<<" ";
	          break;
	}
      cout<<"Enter an option\n1-push\n2-pop\n3-top\n4-print\n5-size\n6-empty\n7-sort\n8-stop"<<endl;
      cin>>option;
    }
   
}
