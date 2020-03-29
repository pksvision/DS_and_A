#include<iostream>
#include<stack>

using namespace std ;

stack<char> st;

bool isOperand(char ch)
{
	return (int(tolower(ch))<=122 && int(tolower(ch))>=97)?true:false;
}

int priority(char ch)
{
	if(ch=='^')
		return 3;
	else if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/')
		return 2;
}

bool isLeftAssociative(char c1, char c2)
{
	if((c1=='+' && c2=='-') || (c1=='-' && c2=='+'))
		return true;
	if((c1=='*' && c2=='/') || (c1=='/' && c2=='*'))
		return true;
}

bool isOperator(char ch)
{
	return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')?true:false;
}

string to_postfix(string exp)
{
	string postfix;
	st.push('(');
	exp.push_back(')');
	for(int i=0;i<exp.length();i++)
	{
		if(isOperand(exp[i]))
			postfix.push_back(exp[i]);
		else if(exp[i]=='(')
			st.push(exp[i]);
		else if (exp[i]==')')
		{
			while(st.top()!='(')
			{
				postfix.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else if(isOperator(exp[i]))
		{
			while( isOperator(st.top()) && ( priority(exp[i])<=priority(st.top()) ))
			{
				postfix.push_back(st.top());
				st.pop();
			}
			st.push(exp[i]);
		}
	}
	while(!st.empty())
	{
		postfix.push_back(st.top());
		st.pop();
	}
	return postfix;
}

int main(int argc, char * argv[])
{
	string expression;
	cout<<"Enter an infix expression "<<endl;
	getline(cin,expression);
	cout<<"Postfix expression is"<<endl<<to_postfix(expression)<<endl;
	return 0;
}