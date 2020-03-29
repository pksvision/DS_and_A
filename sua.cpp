#include<iostream>
#include<vector>

using namespace std;

class Stack
{
	private:
		std::vector<int> values;
	public:
		void push(int value)
		{
			values.push_back(value);
		}
		void pop()
		{
		  if(values.size()==0)
		    cout<<"Stack is already empty. Nothing to Pop out."<<endl;
		  else
		    values.erase(values.begin()+values.size()-1);
		}
		int top()
		{
		  if(values.size()!=0)
		    return values[values.size()-1];
		  else
		    {
		      cout<<"Stack is empty. Returning a default value 0"<<endl;
		      return 0;
		    }
		}
		bool empty()
		{
			return (values.size()==0)?true:false;
		}
		int size()
		{
			return values.size();
		}
		void print()
		{
		  if(values.size()!=0)
		    {
			std::vector<int>::iterator it;
			for(it=values.begin(); it!=values.end(); it++)
				{
					cout<<(*it)<<" ";
				}
			cout<<endl;
		    }
		  else
		    cout<<"Stack is already empty. Nothing to Show"<<endl;
		}
};

int main(int argc, char * argv[])
{
	Stack obj;
	cout<<"Enter an option\n1-push\n2-pop\n3-top\n4-empty?\n5-size?\n6-print\n7-exit"<<endl;
	int opt;
	cin>>opt;
	while(opt!=7)
	  {
	    switch(opt)
	      {
	      case 1: cout<<"Enter a value to be pushed into the stack"<<endl;
		      int val;
		      cin>>val;
		      obj.push(val);
		      break;
	      case 2: obj.pop();
		      break;
	      case 3: cout<<"Top value of the stack is "<<obj.top()<<endl;
		      break;
	      case 4: if(obj.empty())
			cout<<"Stack is empty"<<endl;
		      else
			cout<<"Stack is not empty"<<endl;
		      break;
	      case 5: cout<<"Size of the Stack is "<<obj.size()<<endl;
		      break;
	      case 6: cout<<"Contents of the Stack are <Bottom to Top Order>"<<endl;
		      obj.print();
		      break;
	      case 7: break;
	      }
	    cout<<"Enter an option\n1-push\n2-pop\n3-top\n4-empty?\n5-size?\n6-print\n7-exit"<<endl;
	    cin>>opt;
	  }
	return 0;
}
