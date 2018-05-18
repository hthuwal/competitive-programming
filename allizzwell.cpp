#include <cstdio>
#define N 150
char mat[N][N];
char st[] = "ALLIZZWELL";
int r,c;
bool isValid(int p,int q)
{
    if(p>=0 && p<r && q<c && q>=0 && mat[p][q]!='#')
        return true;
    return false;
}
bool dfs(int x,int y,int px,int py,char s[],int ptr)
{
    if(s[ptr]=='\0')
        return true;
    if(!isValid(x,y))
        return false;
    if(mat[x][y]!=s[ptr])
        return false;
    mat[x][y]='#';
    if(dfs(x,y+1,x,y,s,ptr+1))
        return true;
    if(dfs(x,y-1,x,y,s,ptr+1))
        return true;
    if(dfs(x+1,y,x,y,s,ptr+1))
        return true;
    if(dfs(x+1,y+1,x,y,s,ptr+1))
        return true;
    if(dfs(x+1,y-1,x,y,s,ptr+1))
        return true;
    if(dfs(x-1,y,x,y,s,ptr+1))
        return true;
    if(dfs(x-1,y+1,x,y,s,ptr+1))
        return true;
    if(dfs(x-1,y-1,x,y,s,ptr+1))
        return true;
    
    mat[x][y]=s[ptr];
    return false;
}
bool ans()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]=='A' && dfs(i,j,-1,-1,st,0))
                return true;
        }
    }
    return false;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)
            scanf("%s",mat[i]);
        
        if(ans()) printf("YES\n");
        else printf("NO\n");
        // for(int i=0;i<r;i++)
        // {
        //     for(int j=0;j<c;j++)
        //         printf("%c",mat[i][j]);
        //     printf("\n");
        // }
        
    }
}