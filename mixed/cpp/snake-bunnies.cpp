#include<iostream>
using namespace std;
struct hc{
    int flag=0;
    int head=0;
    int tail=0;
};
hc bunny[10];
hc snake[26];
int identify(char a)
{
    if(a=='-')
        return -1;
    else if(a>='0' && a<='9')
        return 1;
    return 0;
}
int main()
{
    int n,m,i,j;
    char board[10201];
    cin>>n;
    n=n*n;
    for(i=n;i>=1;i--)
    {
        cin<<board[i];
        if(identify(board[i])==1)
        {
            int l = board[i]-'0';
            if(bunny[l].flag==0)
            {
                bunny[l].head=i;
                bunny[l].flag=1;
            }
            else
                bunny[l].tail=i;
        }
        else if(identify(board[i])==0)
        {
            int l = board[i]-'a';
            if(snake[l].flag==0)
            {
                snake[l].head=i;
                snake[l].flag=1;
            }
            else
                snake[l].tail=i;
        }
    }
}
