#include<iostream>
#include<string>
using namespace std;

struct node
{
	int recharge=0;
	int user_id;
	struct node* left_child=NULL;
	struct node* right_child=NULL;
	int height=0;
};


class AVL
{
public:
	node *root=NULL;
public:
	
	node* search(int user_id,node* x);
	node* insert(int user_id,int recharge,node* x);
	node *rroot();
};


int max(int a,int b)
{
	if(a>=b) return a;
	else return b;
}

int height(node *x)
{
	if(x==NULL)
		return 0;
	else return x->height;
}


node* right_rotate(node *x)
{
	node *y=x->left_child;
	node *z=y->right_child;

	y->right_child=x;
	x->left_child=z;

	y->height=1+max(height(y->left_child),height(y->right_child));
	x->height=1+max(height(x->left_child),height(x->right_child));

	return y;

}

node *left_rotate(node *x)  
{  
    node *y = x->right_child;  
    node *T2 = y->left_child;  
  
    // Perform rotation  
    y->left_child = x;  
    x->right_child = T2;  
  
    // Update heights  
    x->height = max(height(x->left_child),     
                    height(x->right_child)) + 1;  
    y->height = max(height(y->left_child),  
                    height(y->right_child)) + 1;  
  
    // Return new root  
    return y;  
}  

int balance(node *x)
{
	return height(x->left_child)-height(x->right_child);
}

int main()
{	
	int n;
	AVL tree;
	cin>>n;
	node* maximum=new node;
	int p=0;
	
	while(1)
	{
		int operation;
		cin>>operation;
		if(operation==1) p++;
		if(p==1&&operation==1)
		{
			int user_id;
			int recharge;
			cin>>user_id;
			cin>>recharge;

			tree.root=tree.insert(user_id,recharge,tree.root);
			maximum->user_id=user_id;
			maximum->recharge=recharge;
		}
		if(operation==1&&p!=1)
		{
			int user_id;
			int recharge;
			cin>>user_id;
			cin>>recharge;
			node* x=tree.search(user_id,tree.rroot());
			if(x==NULL) 
			{
				tree.insert(user_id,recharge,tree.rroot());
				if(maximum->recharge<recharge)
				{
					maximum->user_id=user_id;
					maximum->recharge=recharge;
				}
			}

			else
			{
				x->recharge =x->recharge+recharge;
				if(maximum->recharge<x->recharge) 
				{
					maximum->user_id=x->user_id;
					maximum->recharge=x->recharge;
				}
			}
		}

		if(operation==2&&p!=0)
			cout<<maximum->user_id<<"\n";

		if(operation==2&&p==0)
			cout<<"no data available"<<"\n";

	}
	
}



node * AVL::rroot()
{
	return root;
}

node* AVL::search(int user_id,node *x)
{
	 if (x==NULL||x->user_id==user_id)
		return x;
	
	else if(x->user_id>user_id)
		return search(user_id,x->left_child);
	
	else
		return search(user_id,x->right_child);
}

node* AVL::insert(int user_id,int recharge,node *x)
{
	if(x==NULL)
		{
			node* p=new node;
			p->user_id=user_id;
			p->recharge=recharge;
			return p;
		}

	 if(x->user_id<user_id)
		{
			x->right_child=insert(user_id,recharge,x->right_child);
		}

	if (x->user_id>user_id)
		{
			x->left_child=insert(user_id,recharge,x->left_child);
		}

	x->height=1+max(height(x->left_child),height(x->right_child));
	
	if(balance(x)>1&&user_id<x->left_child->user_id)
	{
		return right_rotate(x);
	}

	if(balance(x)>1&&user_id>x->left_child->user_id)
	{
		x->left_child=left_rotate(x->left_child);
		return right_rotate(x);
	}

	 if(balance(x)<-1&&user_id>x->right_child->user_id)
	{
		return left_rotate(x);
	}

	if (balance(x)<-1&&user_id<x->right_child->user_id)
	{
		x->right_child=right_rotate(x->right_child);
		return left_rotate(x);
	}


	
}
