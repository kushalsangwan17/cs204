#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<stack>
using namespace std;



struct node
{
	string data;
	struct node* left_child=NULL;
	struct node* right_child=NULL;
	struct node* parent=NULL;
};

class tree
{
public:
	node* root=NULL;
};


tree expressiontree1(tree t1,string s,tree t2);
tree expressiontree(string s);
tree buildexpressiontree(string s);
int evaulate(node* p);
int compare_priority(tree ,tree t2);



int main()
{
	int num;
	cin>>num;
	while(num>0)
	{
		int kk;
		cin>>kk;
		map<char,string> var;
		while(kk>0)
		{	
			string s;
			cin>>s;
			
			if(s[1]=='=')
			{
				bool matched=false;
				for(auto x=var.begin();x!=var.end();x++)
				{
					if(x->first==s[0]) 
					{
						matched=true;
						break;
					}
				}

				string s2=s.substr(2,s.length());
				cout<<"\t my rhs is "<<s2;
				
			
				
				for(auto x=var.begin();x!=var.end();x++)
				{
					for(int i=0;i!=s2.length();i++)
					{	
						if(x->first==s2[i])
						{
							
							if(i==0&&s2.length()==1) s2=x->second;
							else if(i==0)
							{	
								string m=s2.substr(i+1,s2.length());
								s2=x->second+m;
							}
							else 
							{	
								string m=s2.substr(i+1,s2.length());
								string q=s2.substr(0,i);
								s2=q+x->second+m;
							}
						}
					}
				}
				
				tree t=buildexpressiontree(s2);
				int j=evaulate(t.root);

				if(!matched)var.insert(pair<char,string>(s[0],to_string(j)));
				else var.at(s[0])=to_string(j);
				
				
			}

			else
			{
				for(auto x=var.begin();x!=var.end();x++)
				{
					for(int i=0;i!=s.length();i++)
					{	
						if(x->first==s[i])
						{
							
							if(i==0&&s.length()==1) s=x->second;
							else if(i==0)
							{	
								string m=s.substr(i+1,s.length());
								s=x->second+m;
							}
							else 
							{	
								string m=s.substr(i+1,s.length());
								string q=s.substr(0,i);
								s=q+x->second+m;
							}
						}
					}
					
				}
				cout<<"\tstring is "<<s;
				tree t=buildexpressiontree(s);
				int i=evaulate(t.root);
				cout<<"\t"<<i;

			}

			kk--;
		}
		num--;
	}
}

int evaulate(node* p)
{
	if(p->left_child==NULL&&p->right_child==NULL)
		return stoi(p->data);
	else
	{
		int x=evaulate(p->left_child);
		int y=evaulate(p->right_child);
		
			if(p->data=="+") return x+y;
			if(p->data=="-") return x-y;
			if(p->data=="*") return x*y;
			if(p->data=="/") return x/y;
			if(p->data=="^") return (int)pow(x,y);
		
	}
}

tree expressiontree(string s)
{
	tree t;
	node* p=new node;
	t.root=p;
	p->data=s;
	return t;
} 

tree expressiontree1(tree t1,tree s,tree t2)
{
	
	
	
	s.root->right_child=t1.root;
	t1.root->parent=s.root;
	s.root->left_child=t2.root;
	t2.root->parent=s.root;
	return s;
} 

tree buildexpressiontree(string s)
{
	stack<tree> my_stack;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(') 
			{
				string s1(1,s[i]);
				my_stack.push(expressiontree(s1));
				
			}
		
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{	
			label:
			int j;
			for( j=i+1;j<s.length();j++)
			{
				if(!(s[j]=='0'||s[j]=='1'||s[j]=='2'||s[j]=='3'||s[j]=='4'||s[j]=='5'||s[j]=='6'||s[j]=='7'||s[j]=='8'||s[j]=='9'))
					break;
			}


			string s1=s.substr(i,j);
			tree t=expressiontree(s1);
			my_stack.push(t);
			i=j-1;
			continue;
		}

		if(s[i]=='*'||s[i]=='/'||s[i]=='^'||s[i]=='+'||s[i]=='-')
		{	
			if(s[i]=='-'&&(i==0||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='^'||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='('))
			{goto label;}

			string s1(1,s[i]);
			tree x=my_stack.top();
			my_stack.pop();
			string p(1,'(');
			

			if(my_stack.empty()||my_stack.top().root->data==p)
			{	
				my_stack.push(x);
				my_stack.push(expressiontree(s1));
			}



			
			
			else
			{
				tree y=my_stack.top();
				int k=compare_priority(expressiontree(s1),y);
				if(k==1)
				{
					my_stack.push(x);
					my_stack.push(expressiontree(s1));
				}

				else
				{	
				my_stack.push(x);
				tree e1=my_stack.top();
				my_stack.pop();
				tree s=my_stack.top();
				my_stack.pop();
				tree e2=my_stack.top();
				my_stack.pop();
				tree t=expressiontree1(e1,s,e2);
				my_stack.push(t);
				my_stack.push(expressiontree(s1));
				}
			}
        }

		
		if(s[i]==')')
		{
			tree t;
			string s2(1,'(');
			tree q=my_stack.top();
			my_stack.pop();
			
			if(my_stack.top().root->data==s2)
			{
				my_stack.pop();
				my_stack.push(q);
			}

			else
			{
				my_stack.push(q);
				while(1)
				{	
					
					tree e1=my_stack.top();
					my_stack.pop();
					tree s=my_stack.top();
					my_stack.pop();
					tree e2=my_stack.top();
					my_stack.pop();
					t=expressiontree1(e1,s,e2);
				
					if(my_stack.top().root->data==s2)
					{
						my_stack.pop();
						my_stack.push(t);
						break;
					}
					my_stack.push(t);
				}
				
				
			}
		}
	}



	
	if(my_stack.size()==1)
	{
		tree t1=my_stack.top();
		return t1;
	}
	
	else
	{
		while(1)
		{
			tree t1=my_stack.top();
			my_stack.pop();
			tree s=my_stack.top();
			my_stack.pop();
			tree t2=my_stack.top();
			my_stack.pop();
			tree t=expressiontree1(t1,s,t2);
			my_stack.push(t);
			if(my_stack.size()==1) return t;
		}

	}
}



int compare_priority(tree s1,tree s2)
{
	map<string,int> out;
	string p("^");

	out.insert(pair<string,int>("+",0));
	out.insert(pair<string,int>("-",0));
	out.insert(pair<string,int>("*",1));
	out.insert(pair<string,int>("/",1));
	out.insert(pair<string,int>("^",2));

	if(s1.root->data==p&&s2.root->data==p) return 1;
	if(out[s1.root->data]>out[s2.root->data]) return 1;
	else return -1;
}
