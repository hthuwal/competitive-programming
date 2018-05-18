#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1111111];

void nextPermutation(int n)
{
    /*Find longest non-increasing suffix*/
    int i=n-1;
    while(i>0 && arr[i-1]>=arr[i])
        i--; 
    //now i is the head index of the suffix
    
    /*Are we already at last permutation*/
    if(i<=0)
        printf("-1\n");
    else{
        /*pivot just before the head of longest non-increasing suffix*/
        /*Find RightMost element that exceeds the pivot **/
        int j=n-1;
        while(arr[j]<=arr[i-1])
            j--;
        
        /*swap pivot with j*/
        int temp = arr[j];
        arr[j]=arr[i-1];
        arr[i-1]=temp;

        /**Sort the suffix in increasing order or in this case since it was 
        already non increasing we can simply reverse it*/
        j=n-1;
        while(i<j){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;j--;
        }
        for(int i=0;i<n;i++)
            printf("%d",arr[i]);
        printf("\n");
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d ",&arr[i]);
        // printf("\n");
        nextPermutation(n);
    }
}