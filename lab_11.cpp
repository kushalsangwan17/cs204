#include<bits/stdc++.h>
using namespace std;
#define ll long long 

struct vertex
{
	int colour;
	int n;
};

ll v,e;


vertex vlist[1000000];



bool bfs(ll i,int* arr)
{
	int c;

	queue<vertex> r;
	vlist[i].colour=0;
	r.push(vlist[i]);
	
	while(!r.empty())
	{
		vertex p=r.front();
		r.pop();
		c=p.colour;
		for(ll k=0;k<v;k++)
		{
			if(*((arr+p.n*v)+k)==1)
			{
				if(vlist[k].colour==-1)
				{
					vlist[k].colour=1-c;
					r.push(vlist[k]);
				}
				else
				{
					if(vlist[k].colour==c)
						return false;
				}
			}
		}

	}

	return true;
}

bool is_bipartite(int *arr)
{
	for(ll i=0;i<v;i++)
	{
		if(vlist[i].colour==-1) // if after the bfs any vertex still remains unvisited then do its bfs
		{
			bool c=bfs(i,arr);
			if(c==false) return false;
		} //if any bfs violates couolourinh that is any one of the components is not bipartie then reutrn false
	}

	return true;
}

int main()
{
	cin>>v>>e;
	int arr[v][v]; //vertex matrix

	for(ll i=0;i<v;i++)
		for(ll j=0;j<v;j++)
			arr[i][j]=0; //make matrix entries equal to 0

	for(ll i=0;i<e;i++)
	{
		int x,y;
		cin>>x;
		cin>>y;
		x=x; // if 1 t0 n vertex then should go to 1 to n-1
		y=y;
		arr[x][y]=1; //  make (0,1) 1 and also (1,0) 1
		arr[y][x]=1;
	}

	for(ll i=0;i<v;i++)
	{
	 // vertex are numbered from 0 to n-1
		vlist[i].colour=-1;
		vlist[i].n=i; // initally they are unvisted by any of the bfs
	}

	if(is_bipartite(&arr[0][0]))
		cout<<"YES";
	else
		cout<<"NO";
}




/*just create a vertex object
store its number as an attribute rangeing from 1 to n maintain an array;
we must have a n*n matrix defining matrices
it should stores 0,1
now start from an edge 1 see 1's row
and do bfs like that*/

