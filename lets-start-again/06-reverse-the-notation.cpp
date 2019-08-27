// https://www.spoj.com/problems/ONP/
	
#include<bits/stdc++.h>
using namespace std;

char OPS [] = {'+', '-', '*', '/', '^'};

bool isOp(char c)
{
	for(auto op: OPS)
	{
		if(op == c)
			return true;
	}
	return false;
}

bool priority(char op1, char op2)
{
	int i=-1, j;
	for(int k=0;k<5;k++)
	{
		if(OPS[k] == op1)
			i = k;

		if(OPS[k] == op2)
			j = k;
	}

	return i >= j;
}

int main()
{
	stack<char> st;
	int t;
	string expr;
	cin.sync_with_stdio(false);

	cin>>t;
	while(t--)
	{
		cin>>expr;
		string rpl;
		for(int i=0;i<expr.length(); i++)
		{
			char c = expr[i];
			if(c == '(')
				st.push('(');
			else if(c == ')')
			{
				while(!st.empty())
				{
					char top = st.top(); st.pop();
					if(top == '(')
						break;
					else
						rpl += top;
				}
			}
			else if(isOp(c))
			{
				while(!st.empty())
				{
					char top = st.top();
					if(priority(top, c))
					{
						rpl += top;
						st.pop();
					}
					else
					{
						st.push(c);
						break;
					}
				}
			}
			else
			{
				rpl += c;
			}
		}
		cout<<rpl<<"\n";
	} 
}