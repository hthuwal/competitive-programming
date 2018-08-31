/*question statement is ambiguous need to find diameter*/
/*apply bfs to find farthest node say a*/
/*apply bfs to find farthest node from a say b. the distance a to b is the diameter*/
/*important : The labyrinth is designed in such a way that there is exactly one 
path between any two free blocks. This implies the free blocks form a connected tree.*/

#include <cstdio>
#include <queue>
using namespace std;
#define N 1100

bool visited[N][N];
char grid[N][N];
queue<int> xq,yq,dist;
int c,r,maxd,maxx,maxy;
bool possible(int x,int y)
{
	if(y>=c || y<0 || x <0 || x>=r || grid[x][y]=='#')
		return false;
	return true;
}
void initialize()
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			visited[i][j]=false;
}
void bfs(int x,int y)
{
	maxd=0,maxx=x,maxy=y;
	visited[x][y]=true;
	xq.push(x);yq.push(y);dist.push(0);
	while(!xq.empty())
	{
		int tx = xq.front();xq.pop();
		int ty = yq.front();yq.pop();
		int td = dist.front();dist.pop();
		
		if(td>maxd)
		{
			maxd=td;maxx=tx;maxy=ty;
		}
		if(possible(tx+1,ty) && !visited[tx+1][ty] )
		{
			visited[tx+1][ty]=true;;
			xq.push(tx+1); yq.push(ty);dist.push(td+1);
		}
		if(possible(tx,ty+1) && !visited[tx][ty+1] )
		{
			visited[tx][ty+1]=true;;
			xq.push(tx); yq.push(ty+1);dist.push(td+1);
		}	
		if(possible(tx-1,ty) && !visited[tx-1][ty] )
		{
			visited[tx-1][ty]=true;
			xq.push(tx-1); yq.push(ty);dist.push(td+1);
		}	
		if(possible(tx,ty-1) && !visited[tx][ty-1] )
		{
			visited[tx][ty-1]=true;
			xq.push(tx); yq.push(ty-1);dist.push(td+1);
		}	
	}
}
int ans()
{
	int p=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(grid[i][j]!='#' && !visited[i][j])
			{
					bfs(i,j);
					// printf("%d %d %d\n",maxx,maxy,maxd);
					initialize();
					bfs(maxx,maxy);
					return maxd;
					// printf("%d %d %d\n",maxx,maxy,maxd);
			}
		}
	}
	return 0;
}
int main()
{
	freopen("in.txt","r",stdin);
	int t;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&c,&r);
		for(int i=0;i<r;i++)
			scanf("%s",grid[i]);
		
		initialize();
		printf("Maximum rope length is %d.\n",ans());
		
	}
	
}