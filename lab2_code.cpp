#include<iostream>
using namespace std;

struct node
{
	int x;
	int y;
	struct node * ptr;
};

typedef struct node node ;

void add_first(int x, int y);
void del_first();
void del(int x, int y);
void search(int d);
void search(int x, int y);
void length();

node* head;

int main(int argc, char const *argv[])
{
	head=new node;
	head=NULL;
	long long int num;
	cin>>num;
	int p,x,y;
	float d;

	while(num>0)
	{
		cin>>p;

		switch(p)
		{
			case 1: cin>>x>>y; add_first(x,y); break;
			case 2: del_first();	break;
			case 3: cin>>x>>y; del(x,y); break;
			case 4: cin>>d; search(d); break;
			case 5: cin>>x>>y; search(x,y); break;
			case 6: length(); break;
		}
		num--;
	}
	return 0;
}

void add_first(int x, int y)
{
	node* temp=new node;
	temp->x=x;
	temp->y=y;
	temp->ptr=NULL;

	if(head==NULL)
		head=temp;
	else
	{
		temp->ptr=head;
		head=temp;
	}
}


void del_first()
{
	if(head==NULL)
	{
		cout<<"-1";
	}

	else
	{
		node* temp=new node;
		temp=head->ptr;
		free(head);
		
		head=temp;
	}

}
void del(int x, int y)
{
	if(head==NULL)
	{
		cout<<"-1";
	}

	else if(head->ptr==NULL)
	{
		if(head->x==x&&head->y==y)
		{
			del_first();
			cout<<"0";
		}
		else cout<<"-1";
	}

	else
	{
		node* temp=new node;
		node* temp1=new node;
		temp=head;
		
		if(temp->x==x&&temp->y==y)
		{
			del_first();
			cout<<"0";
			return;
		}
		

		while(temp->ptr!=NULL)
		{
			if(temp->ptr->x==x&&temp->ptr->y==y) break;
			temp=temp->ptr;

		}

		if(temp->ptr==NULL)
			cout<<"-1";
		
		else
		{
			temp1=temp->ptr->ptr;
			free(temp->ptr);
			temp->ptr=temp1;
			cout<<"0";
		}
	}
}
void search(int d)

{
	if(head==NULL)
	{
		cout<<"-1";
	}

	else
	{
		node* temp=new node;
		temp=head;
		int n=0;

		while(temp!=NULL)
		{
			if(d*d>=temp->x*temp->x+temp->y*temp->y) 
			{
				cout<<"("<<temp->x<<","<<temp->y<<")"<<",";
				n++;
			}
			temp=temp->ptr;

		}
		
		if(n===0) cout<<"-1";
	}
}

void search(int x, int y)

{
	if(head==NULL)
	{
		cout<<"false";
	}

	else
	{
		node* temp=new node;
		temp=head;

		while(temp!=NULL)
		{
			if(temp->x==x&&temp->y==y){ cout<<"true"; break; }
			temp=temp->ptr;

		}
                if(temp==NULL) cout<<"false";
	}
}

void length()
{
 	int count=0;
 	node* temp = new node;
 	temp=head;
 	while(temp!=NULL)
 	{
 		count++;
 		temp=temp->ptr;
 	}
 	cout<<count;
}


