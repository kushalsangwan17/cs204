#include<bits/stdc++.h>
using namespace std;
#define ll int



struct vertex
{
	int colour;
	int number;
	int weight;
};

class graph
{
	public:
	vector<vector<vertex>> vec; // contains list of vertexes adjacent to every vertex
	vector<vertex> visited; // contains  info about which vertex have been visited
	int n; // num_vertex in the graph
	void create_edge(int x,int y,int weight);  // creates an edge as inputs ar egiven
	void create_pseudo(int x,int y,int weight); // create pseduo edges and noes for even wights

};



void graph::create_edge(int x,int y,int weight)
{
	if(weight%2==0) weight=2;
	else weight=1;
	vertex i={-1,x,weight}; // create verttex to be pushed into adjaceny list
	vertex j={-1,y,weight};
	vec[x].push_back(j); // put crossly into adjaceny list
	vec[y].push_back(i);
}

void graph::create_pseudo(int x,int y,int weight)
{
	vector<vertex> v={};
	vec.push_back(v);
	n++;
	visited.push_back({-1,n-1,1});
	vertex c={-1,n-1,1};
	vec[x].push_back(c);
	vec[y].push_back(c);
	vec[n-1].push_back({-1,x,1});
	vec[n-1].push_back({-1,y,1});
}

graph g; //making graph global

bool bfs(int i) // i is index of no. nodes to be done bfs with
{
	int c; // colour  of root for now 0

	queue<vertex> r;
	g.visited[i]={0,i,1};
	r.push(g.visited[i]);
	
	while(!r.empty())
	{
		vertex p=r.front();
		r.pop();
		c=p.colour;
		for(auto j=g.vec[p.number].begin();j!=g.vec[p.number].end();j++)
		{
			
				if(g.visited[(*j).number].colour==-1)
				{
					g.visited[(*j).number]={1-c,(*j).number,1};
					r.push(g.visited[(*j).number]);
				}
				else
				{
					if(g.visited[(*j).number].colour==c)
						return false;
				}
			
		}

		c=1-c;

	}

	return true;
}

bool is_bipartite()
{
	for(ll i=0;i<g.n;i++)
	{
		if(g.visited[i].colour==-1) // if after the bfs any vertex still remains unvisited then do its bfs
		{
			bool c=bfs(i);
			if(c==false) return false;
		} //if any bfs violates couolourinh that is any one of the components is not bipartie then reutrn false
	}

	return true;
}

int main()
{
	int v;
	int e;
	cin>>v>>e;
	
	vector<vertex> r={};
	for(int i=0;i<v;i++ )
	{
		g.vec.push_back({}); // make n empty adjaceny ;ists
		g.visited.push_back({-1,i,1}); // make visited false for all vertices
	}
	g.n=v;

	for(int i=0;i<e;i++)
	{
		int x,y,weight;
		cin>>x;
		cin>>y;
		cin>>weight;
		g.create_edge(x,y,weight);
		if(weight%2==0) g.create_pseudo(x,y,weight);
	}


	if(is_bipartite())
		cout<<"YES";
	else
		cout<<"NO";
} 