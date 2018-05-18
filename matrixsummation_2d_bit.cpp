#include <cstdio>
#define N 1100
int mat[N][N];
int bit[N][N];
/**
 * Initializes all elements of both matrix and bit2d to 0
 * @param n [size of matrix nxn]
 */
void init(int n)
{
    for(int i=0;i<=n+5;i++)
        for(int j=0;j<=n+5;j++)
        {
            mat[i][j]=0;
            bit[i][j]=0;
        }
}
/**
 * A function to update 2d BIT set mat[x][y]=num
 * @param x   [row of the element]
 * @param y   [col of the element]
 * @param num [new value of that element]
 * @param n   [size of matrix]
 */
void update_2d_bit(int x,int y,int num,int n)
{
    int old = mat[x][y];
    mat[x][y]=num;
    for(int i=x;i<=n;i+=(i&-i))
        // This loop update all the 1D BIT inside the
        // array of 1D BIT = BIT[x]
        for(int j=y;j<=n;j+=(j&-j))
            bit[i][j]+=(num-old);
}

/**
 * A function to get sum from (1, 1) to (x, y)
 * @param  x [ row number of opposite end of diagonal ]
 * @param  y [ col number of opposite end of diagonal ]
 * @return   [ sum of all elements in the matrix having (1,1) and (x,y)
 *             as opposite ends of the diagonal ]
 */
int getsum_2d_bit(int x,int y)
{
    int sum=0;
    for(int i=x;i>0;i-=(i&-i))
        for(int j=y;j>0;j-=(j&-j))
            sum+=bit[i][j];
    return sum;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n,x,y,num,p,q;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        init(n);
        char in[5];
        // print(n);
        // printf("\n");
        while(1)
        {
            scanf("%s",in);
            // printf("%s\n",in);
            if(in[1]=='E')
            {
                scanf("%d %d %d",&x,&y,&num);
                x++;y++;
                update_2d_bit(x,y,num,n);
            }
            /**
             * To Find ind sum of elements in matrix whose diagonal has opposite ends
             * A(x,y) and B(p,q) and O(1,1) is the origin
             * $ => elements summed
             *
             * Required			I          II          III          IV
             * # # # # #	$ $ $ $ #	$ $ # # #	$ $ $ $ #	$ $ # # #	
             * # # # # #	$ $ $ $ #	$ $ # # #	$ $ $ $ #	$ $ # # #	
             * # # $ $ #	$ $ $ $ #	$ $ # # #	# # # # #	# # # # #	
             * # # $ $ #	$ $ $ $ #	$ $ # # #	# # # # #	# # # # #	
             * # # # # #	# # # # #	# # # # #	# # # # #	# # # # #	
             *
             * Required sum = I - II - III + IV
             */
            else if(in[1]=='U')
            {
                scanf("%d %d %d %d",&x,&y,&p,&q);
                x++;y++;p++;q++;
                int sum = getsum_2d_bit(p,q)
                        + getsum_2d_bit(x-1,y-1)
                        - getsum_2d_bit(x-1,q)
                        - getsum_2d_bit(p,y-1);
                printf("%d\n",sum);
            }
            else
                break;
            // print(n);
            // printf("\n");
        }
        printf("\n");
    }
}