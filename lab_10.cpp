#include<bits/stdc++.h>
using namespace std;
int n;
int m;

int ccount=0;

int current_col=0;

bool is_valid(int x,int y,int key,int** input,int** visited)
{
	if(x<m&&y<n&&key==input[x][y]&&visited[x][y]==0)
		return true;
	else
		return false;
}

void dfs(int x,int i,int j,int** input,int** visited)
{
	int x_move[4]={0,0,1,-1};
	int y_move[4]={1,-1,0,0};
	ccount++;
	visited[i][j]=1;
	for(int u=0;u<4;u++)
	{
		if(is_valid(i+x_move[u],j+y_move[u],x,input,visited))
		{
			dfs(x,i+x_move[u],j+y_move[u],input,visited);
		}
	}
}

int largest_component(int** input,int** visited)
{
	int current_max=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			int x=input[i][j];
			if(visited[i][j]==0)
				dfs(x,i,j,input,visited);
			if(ccount>current_max) 
				current_max=ccount;
				current_col=x;
			ccount=0;
		}
	return current_max;
}

int main()
{
	int c;
	cin>>m>>n>>c;
	int input[m][n];
	int visited[m][n];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			cin>>input[i][j];
			visited[i][j]=0;
		}
	int p=largest_component(input,visited);
	cout<<p<<current_col;
}