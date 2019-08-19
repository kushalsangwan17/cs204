

#include<iostream>
using namespace std;

struct node
{
	string data;
	struct node* left_child;
	struct node* right_child;
	struct node* parent;
}

class tree
{
	public:
	node * root;
}


int evaulate(node* p)
{
	if(p->left_child==NULL)
		return stoi(p->data);
	else
	{
		x=evaulate(p->left_child);
		y=evaulate(p->right_child);
		switch(p->data)
		{
			case '+': return x+y;
			case '-': return x-y;
			case '*': return x*y;
			case '/': return x/y;
			case '^': return (int)pow(x,y);
		}
	}
}

tree buildexpressiontree(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(') my_stack.push("(",1);
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			for(int j=1;i+j<s.length();j++)
			{
				if(!(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'))
				{
					break;
				}
			}

			string s1=s.substr(i,j);
			tree t=expression_tree1(s1);
			stack.push(t);
		}

		if(s[i]=='*'||s[i]=='/'||s[i]=='^'||s[i]=='+'||s[i]=='-')
		{
			auto x=stack.pop();
			if(stack.is_empty())
			{	
				stack.push(x);
				tree e1=stack.pop();
				string s3=stack.pop();
				tree e2=stack.pop();
				tree t=expression_tree(e1,s3,e2);
				stack.push(t,0);
			}

			else
			{
				auto y=stack.pop();
				int k=compare_priority(s[i],y);
				if(k>0)
					stack.push(s[i],1);
				else
				{	
				stack.push(x);
				stack.push(y);
				tree e1=stack.pop();
				string s3=stack.pop();
				tree e2=stack.pop();
				tree t=expression_tree(e1,s3,e2);
				stack.push(t,0);
				stack.push(s[i],1);
				}
			}



		}

		if(s[i]==')')
		{
			while(1)
			{
				tree e1=stack.pop();
				string s3=stack.pop();
				tree e2=stack.pop();
				tree t=expression_tree(e1,s3,e2);
				if(stack.top()='(')break;
			}
				stack.push(t,0);
		}
	}

	tree t1=stack.pop()
	return t1;
}

tree expressiontree1(string s)
{
	tree t;
	node *p=new node;
	
	p->left_child=NULL;
	p->right_child=NULL;
	p->data=s;
	tree.root=p;
	return t;
} 

tree expressiontree1(tree t1,string s,tree t2)
{
	tree t;
	node *p=new node;
	p->left_child=t1.root();
	p->right_child=t2.root();
	p->data=s;
	t.root=p;
	return t;
} 


int main()
{
	int num;
	cin>>num;
	while(num>0)
	{
		int kk;
		cin>>kk;
		while(kk>0)
		{	
			string s;
			cin>>s;
			tree t=buildexpressiontree(s);
			int i=evaulate(t.root());
			cout<<i;
			kk--;
		}
		num--;
	}
}

