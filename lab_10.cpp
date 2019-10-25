#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int visited[1000][1000];

int ccount=0;

int current_col=0;

bool is_valid(int x,int y,int key,int* input)
{
	if(x<m&&y<n&&y>=0&&x>=0&&key==*((input+x*n) + y)&&visited[x][y]==0)
		return true;
	else
		return false;
}

void dfs(int x,int i,int j,int* input)
{
	int x_move[4]={0,0,1,-1};
	int y_move[4]={1,-1,0,0};
	ccount++;
	visited[i][j]=1;
	for(int u=0;u<4;u++)
	{
		if(is_valid(i+y_move[u],j+x_move[u],x,input))
		{
			dfs(x,i+y_move[u],j+x_move[u],input);
		}
	}
}

int largest_component(int* input)
{
	int current_max=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			int x= *((input+i*n) + j);
			if(visited[i][j]==0)
				dfs(x,i,j,input);
			if(ccount>current_max) 
				{
					current_max=ccount;
					current_col=x;
				}
			ccount=0;
		}
	return current_max;
}

int main()
{
	int c;
	cin>>m>>n>>c;
	int input[m][n];
	

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			cin>>input[i][j];
			visited[i][j]=0;
		}
	int p=largest_component(&input[0][0]);
	cout<<p<<" "<<current_col; 
}


/*
8 
6
4
1 4 4 4 4 3 3 1
2 1 1 4 3 3 1 1
3 2 1 1 2 3 2 1
3 3 2 1 2 2 2 2
3 1 3 1 1 4 4 4
1 1 3 1 1 4 4 4
*/