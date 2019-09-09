#include<bits/stdc++.h>
using namespace std;

struct node
{
	node* children[10];
	string s=""; 
	node();
	bool leaf=false;
	int number=0;
};

node::node()
{
	for(int i=0;i<10;i++)
	{
		children[i]=NULL;
	}
}

class trie
{
	
public:
	node* root;
	void insert(string s);
	void preorder(node* current);
	trie();
};

bool leaf(node* p)
{
	if(p->leaf==true)
		return true;
	else
		return false;
}

trie:: trie()
{
	root=new node;
}

void trie::insert(string s)
{
	node* parent=root;
	for(int i=0;i<s.length();i++)
	{
		int q=s[i]-48;
		if(parent->children[q]==NULL) parent->children[q]=new node;
		
		parent=parent->children[q];
		if(i==s.length()-1)
		{
			 parent->leaf=true;
			 parent->s=s.substr(0,i+1);
			 parent->number++;
		}
	}
}

void trie::preorder(node *current)
{
	
	if(current!=NULL)
	{
		if(leaf(current)==true) 
			{
				int p=current->number;
				while(p>0)
				{
					cout<<current->s;
					p--;
				}
			}

		for(int i=9;i>=0;i--)
		{
			preorder(current->children[i]);
		}
	}
}



int main()
{
	int testcases;
	cin>>testcases;
	while(testcases>0)
	{
		int num_string;
		cin>>num_string;
		trie tree;
		while(num_string>0)
		{
			string s;
			cin>>s;
			tree.insert(s);
			num_string--;
		}

		tree.preorder(tree.root);

		testcases--;
	}
}
