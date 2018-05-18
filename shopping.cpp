#include <cstdio>
#include <climits>
#include <set>
#include <utility>
using namespace std;
#define N 27
#define triple pair<int,pair<int,int> >
char store[N][N];

void print(int w,int h)
{
    for(int i=0;i<h;i++)
        printf("%s\n",store[i]);
}
bool isvalid(int x,int y,int r,int c)
{
    if(x<0 || y<0 || x>=r || y>=c || store[x][y]=='X')
        return false;
    return true;
}
int dijsktra(int w,int h)
{
    int sx,sy,dx,dy;
    int dist[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            if(store[i][j]=='S') 
            {
                store[i][j]='0';
                dist[i][j]=0;
                sx=i;sy=j;
            }
            else if(store[i][j]=='D')
            {
                store[i][j]='0';
                dx=i;dy=j; 
                dist[i][j]=INT_MAX;
            }
            else
                dist[i][j]=INT_MAX;
        }

    set<triple> heap;
    heap.insert(make_pair(0,make_pair(sx,sy)));
    while(!heap.empty())
    {
       triple cur = *(heap.begin());
       heap.erase(heap.begin());

       int curx = cur.second.first;
       int cury = cur.second.second;

       /**Traversing Neighbors**/
       int nx = curx;
       int ny=cury-1;
       if(isvalid(nx,ny,h,w))
       {
            int c = store[nx][ny]-'0';
            if(dist[nx][ny] > dist[curx][cury]+c)
            {
                if(dist[nx][ny]!=INT_MAX)
                    heap.erase(heap.find(make_pair(dist[nx][ny],make_pair(nx,ny))));
                dist[nx][ny]=dist[curx][cury]+c;
                heap.insert(make_pair(dist[nx][ny],make_pair(nx,ny)));
            }
       }
        /**Traversing Neighbors**/
       nx = curx;ny=cury+1;
       if(isvalid(nx,ny,h,w))
       {
            int c = store[nx][ny]-'0';
            if(dist[nx][ny] > dist[curx][cury]+c)
            {
                if(dist[nx][ny]!=INT_MAX)
                    heap.erase(heap.find(make_pair(dist[nx][ny],make_pair(nx,ny))));
                dist[nx][ny]=dist[curx][cury]+c;
                heap.insert(make_pair(dist[nx][ny],make_pair(nx,ny)));
            }
       }
        /**Traversing Neighbors**/
       nx = curx-1;ny=cury;
       if(isvalid(nx,ny,h,w))
       {
            int c = store[nx][ny]-'0';
            if(dist[nx][ny] > dist[curx][cury]+c)
            {
                if(dist[nx][ny]!=INT_MAX)
                    heap.erase(heap.find(make_pair(dist[nx][ny],make_pair(nx,ny))));
                dist[nx][ny]=dist[curx][cury]+c;
                heap.insert(make_pair(dist[nx][ny],make_pair(nx,ny)));
            }
       }
        /**Traversing Neighbors**/
       nx = curx+1;ny=cury;
       if(isvalid(nx,ny,h,w))
       {
            int c = store[nx][ny]-'0';
            if(dist[nx][ny] > dist[curx][cury]+c)
            {
                if(dist[nx][ny]!=INT_MAX)
                    heap.erase(heap.find(make_pair(dist[nx][ny],make_pair(nx,ny))));
                dist[nx][ny]=dist[curx][cury]+c;
                heap.insert(make_pair(dist[nx][ny],make_pair(nx,ny)));
            }
       }
    }
    return dist[dx][dy];
}
int main()
{
    freopen("in.txt","r",stdin);
    int w,h;
    while(1)
    {
        scanf("%d %d",&w,&h);
        if(w==0)
            break;
        for(int i=0;i<h;i++)
            scanf("%s",store[i]);
        // print(w,h);
        printf("%d\n",dijsktra(w,h));
    }

}