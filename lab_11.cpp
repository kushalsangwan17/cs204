#include<bits/stdc++.h>
using namespace std;
#define ll long long 

struct vertex
{
	int n;
	int colour;
};

ll v,e;


vertex vlist[1000000];



bool bfs(ll i,int* arr)
{
	int c;

	queue<vertex> r;
	r.push(vlist[i]);
	vlist[i].colour=0;
	while(!r.empty())
	{
		vertex p=r.front();
		r.pop();
		c=p.colour;
		for(ll k=0;k<v;k++)
		{
			if(*((arr+i*v)+k)==1)
			{
				if(vlist[k].colour==-1)
				{
					vlist[k].colour=1-c;
				}
				else
				{
					if(vlist[k].colour!=c)
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
		for(ll j=0;i<v;i++)
			arr[i][j]=0; //make matrix entries equal to 0

	for(ll i=0;i<e;i++)
	{
		int x,y;
		cin>>x;
		cin>>y;
		x=x-1; // if 1 t0 n vertex then should go to 1 to n-1
		y=y-1;
		arr[x][y]=1; // if (1,2) is entry make (0,1) 1 and also (1,0) 1
		arr[y][x]=1;
	}

	for(ll i=0;i<v;i++)
	{
		vlist[i].n=i; // vertex are numbered from 0 to n-1
		vlist[i].colour=-1; // initally they are unvisted by any of the bfs
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

