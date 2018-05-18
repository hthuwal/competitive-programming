#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int check(char ***mat,int r,int c, int i,int j,char *pattern,int x,int p)
{
    if(i<0 || i>=r || j<0 ||j>=c)
        return 0;
    else{
        int sum=0;
        if(mat[i][j][0]==pattern[x])
        {
            if(pattern[x+1]=='\0')
                return 1;
            switch(p){
                case 2: sum+=check(mat,r,c,i+1,j,pattern,x+1,2); break;
                case 3: sum+=check(mat,r,c,i-1,j+1,pattern,x+1,3); break;
                case 4: sum+=check(mat,r,c,i,j+1,pattern,x+1,4); break;
                case 5: sum+=check(mat,r,c,i+1,j+1,pattern,x+1,5); break;
            }
        }
        return sum;
    }
}
int word_count(int input1_size_rows, int input1_size_cols, char*** input1,char* input2)
{
    int i,j,ans=0;
    for(i=0;i<input1_size_rows;i++)
    {
        for(j=0;j<input1_size_cols;j++)
        {
            
            ans+=(check(input1,input1_size_rows,input1_size_cols,i,j,input2,0,2));
            ans+=(check(input1,input1_size_rows,input1_size_cols,i,j,input2,0,3));
            ans+=(check(input1,input1_size_rows,input1_size_cols,i,j,input2,0,4));
            ans+=(check(input1,input1_size_rows,input1_size_cols,i,j,input2,0,5));
        }
    }
    return ans;
    //Write code here
}

int main() {
    freopen("in.txt","r",stdin);
    int output = 0;
    int ip1_rows = 0;
    int ip1_cols = 0;
    scanf("%d", &ip1_rows);
    scanf("%d", &ip1_cols);
    
    char*** ip1 = (char***)malloc(ip1_rows*sizeof(char**));
    int ip1_init_i=0;
    for(ip1_init_i=0 ; ip1_init_i<ip1_rows ; ++ip1_init_i)
    {
        ip1[ip1_init_i] = (char**)malloc(ip1_cols*(sizeof(char*)));
    }
    
    int ip1_i, ip1_j;
    for(ip1_i = 0; ip1_i < ip1_rows; ip1_i++) {
        for(ip1_j = 0; ip1_j < ip1_cols; ip1_j++) {
            char* ip1_item;
            ip1_item = (char *)malloc(51200 * sizeof(char));
            scanf("%s",ip1_item);
            
            ip1[ip1_i][ip1_j] = ip1_item;
        }
    }
    char* ip2;
    ip2 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip2);
    output = word_count(ip1_rows, ip1_cols,ip1,ip2);
    printf("%d\n", output);
    return 0;
}