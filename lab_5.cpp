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
string replace_by_value(map<string,string>::iterator x,string s);


 // to know whether statement does variable assingment


int main()
{
	int num;
	cin>>num;
	while(num>0)
	{
		int kk;
		cin>>kk;
		
		map<string,string> var;
		while(kk>0)
		{	
			string s;
			cin>>s;
			int sign1=1;
			int sign2=1;
			bool assignment=false;
			
			if(s[0]=='-'&&s[1]=='(')
			{	
				sign1 =-1;
				s=s.substr(1,s.length());
			}
			
			int g;
			for( g=0;g<s.length();g++)
			{
				if(s[g]=='=') 
				{
					assignment=true;
					break;
				}
			}


			
			if(assignment)
			{
				bool matched=false;
				string o=s.substr(0,g);
				for(auto x=var.begin();x!=var.end();x++)
				{
					if(x->first==o) 
					{
						matched=true;
						break;
					}
				}

				string s2=s.substr(g+1,s.length());

				if(s2[0]=='-'&&s2[1]=='(')
				{	
					sign2 =-1;
					s2=s2.substr(1,s2.length());
				}
				
				for(auto x=var.begin();x!=var.end();x++)
				{
					
						s2=replace_by_value(x,s2);
				}
				
				tree t=buildexpressiontree(s2);
				int j;
				
				j=sign2*evaulate(t.root);
				
				if(!matched)var.insert(pair<string,string>(o,to_string(j)));
				else var.at(o)=to_string(j);
				
				
			}

			else
			{
				for(auto x=var.begin();x!=var.end();x++)
				{
					s=replace_by_value(x,s);
				}
				bool undeclared=false;
				for(int j=0;j<s.length();j++)
				{
					if(!(s[j]=='0'||s[j]=='1'||s[j]=='2'||s[j]=='3'||s[j]=='4'||s[j]=='5'||s[j]=='6'||s[j]=='7'||s[j]=='8'||s[j]=='9'||s[j]=='*'||s[j]=='/'||s[j]=='^'||s[j]=='+'||s[j]=='-'||s[j]=='('||s[j]==')'))
						undeclared=true;

				}

				if(undeclared) 
				{
					cout<<"cant be evaulated\n";
					continue;
				}
				
				tree t=buildexpressiontree(s);
				int i;				
				i=sign1*evaulate(t.root);
				cout<<i<<"\n";

			}

			kk--;
		}
		num--;
	}
}

int evaulate(node* p)
{
	if(p->left_child==NULL&&p->right_child==NULL)
	{	
		int minus_count=0;
		string q("-");
		int i;
		for( i=0;i!=p->data.length();i++)
		{
			
			if(p->data[i]!='-') break;
			minus_count++;
		}

		p->data=p->data.substr(i,p->data.length());
		string m1=q+p->data;
		if(minus_count%2==1) return	stoi(m1);
		else return stoi(p->data);



	}
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
			int number=0;
			for( j=i+1;j<s.length();j++)
			{
				if(s[i]!='-')				
				{
					if(!(s[j]=='0'||s[j]=='1'||s[j]=='2'||s[j]=='3'||s[j]=='4'||s[j]=='5'||s[j]=='6'||s[j]=='7'||s[j]=='8'||s[j]=='9'))
					break;
				}
				
				if(s[i]=='-')
				{
					if(s[j]=='0'||s[j]=='1'||s[j]=='2'||s[j]=='3'||s[j]=='4'||s[j]=='5'||s[j]=='6'||s[j]=='7'||s[j]=='8'||s[j]=='9') number++;
					if(number!=0)
					{
					if(!(s[j]=='0'||s[j]=='1'||s[j]=='2'||s[j]=='3'||s[j]=='4'||s[j]=='5'||s[j]=='6'||s[j]=='7'||s[j]=='8'||s[j]=='9'))
					break;
					}
					
					if(number==0) continue;
				
				}
					
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

string replace_by_value(map<string,string>::iterator x,string s)
{	
	int found=-1;

	while(1)
	{
		found=s.find(x->first,found+1);
		if(found==string::npos)
			return s;
		else
			s.replace(found,x->first.length(),x->second);
	}
}
