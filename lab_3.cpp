#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool Is_Balanced(string s)
{
	stack<char> p;
	int q=0 ;// to track the number of '|' brackets
	for(auto i=s.begin();i!=s.end();i++)
	{
		if(*i=='<'||*i=='{'||*i=='|'||*i=='('||*i=='[')
		{	
			if(*i=='|')
				q++;
			p.push(*i);
		}

		if(q%2==0&&*i=='|')
		{
			p.pop();
			if(p.top()=='|')
				p.pop();
			else
				p.push('|');
		}

		if(p.empty()&&(*i=='>'||*i=='}'||*i==']'||*i==')'))
			return false;

		if(*i=='>'||*i=='}'||*i==']'||*i==')')
		{
			if(*i=='>')
			{
				if(p.top()=='<')
					p.pop();
				else
					return false;
			}

			if(*i=='}')
			{
				if(p.top()=='{')
					p.pop();
				else
					return false;
			}

			if(*i==']')
			{
				if(p.top()=='[')
					p.pop();
				else
					return false;
			}

			if(*i==')')
			{
				if(p.top()=='(')
					p.pop();
				else
					return false;
			}
		}

		
	}

	if(p.empty())
		return true;
	else
		return false;
}

int main()
{	long int p;
	cin>>p;
	
	while(p>0)
	{
	string s;
	cin>>s;

	bool t;
	t=Is_Balanced(s);
	if(t==true) cout<< "yes";
	else cout<<"no";
	p--;
	}

	return 0;
}
