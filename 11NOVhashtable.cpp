#include<bits/stdc++.h>
using namespace std;

struct node
{
	string key;
	struct node* next=NULL;
};



int hash_function(string str,int d)
{
    unsigned long int hash;
    int c;
    
    hash = 5381;
    for (auto x: str)
    {
        c = x;
        hash = ((hash << 5) + hash) + c; 
        
    }
    return (int(hash % d));
}

class hash_table
{
	public:

	vector<node *> buckets;
	int d;
	
	hash_table(int c)
	{
		d=c;
		for(int i=0;i<c;i++)
		{
			buckets.push_back(NULL);
		}
	}

	void insert(string key)
	{
		int num;
		node* q=new node;
		q->key=key;
		num=hash_function(key,d);
		if(buckets[num]==NULL)
		{
			buckets[num]=q;
		}
		else
		{
			node* temp=buckets[num];
			buckets[num]=q;
			q->next=temp;
		}

	}

	node* search(string key)
	{
		int num;
		num=hash_function(key,d);
		node *temp=buckets[num];
		while(temp!=NULL&&temp->key!=key)
		{
			temp=temp->next;
		}

		/*if(temp==NULL) cout<<"not found";
		else cout<<"present";*/
		return temp;
	}

	void del(string key)
	{
		node *x=search(key);
		int num=hash_function(key,d);
		if(x==NULL) 
			cout<<"key not present \n";
		else
		{
			if(x->next=NULL)
			{
				buckets[num]=NULL;
				free(x);
			}

			else
			{
				if(buckets[num]==x)
				{
					node *y=x->next;
					buckets[num]=y;
					free(x);
				}

				else
				{
					node *p=buckets[num];
					while(p->next!=x)
					{
						p=p->next;
					}

					node *temp=x->next;
					p->next=temp;
					free(x);
				}			
			}

		}	
	}

	void traversal()
	{
		for(int i=0;i<d;i++)
		{
			node* x=buckets[i];
			cout<<i<<" ";
			
			while(x!=NULL)
			{
				
				cout<<x->key<<" ";
				x=x->next;
			}

			cout<<" \n";
		}
	}

};

int main()
{
	hash_table s(111323);
	int z;
	cin>>z;
	int n=z;
	bool found=false;
	while(n>0)
	{
		string word;
		cin>>word;
		string z=word;
		reverse(word.begin(),word.end());
		if(z!=word)
		{
			if(s.search(word)==NULL)
				s.insert(z);
			else
			{
				found=true;
				break;
			}
			
		}
		n--;
	}

	if(found)
		cout<<"YES";
	else
		cout<<"NO";

}