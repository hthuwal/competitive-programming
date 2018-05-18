#include <cstdio>
#include <vector>
using namespace std;

#define N 111111
struct duo{
    long long int a,b;
};

long long int day[N];
long long int lect[N];
long long int sad[N];
duo temp = {0,0};
vector<duo> heap(N,temp);
long long int heapsize=0;
long long int total_sadness;
vector<duo> list[N];

void max_heapify(long long int i){
    long long int left = i<<1;
    long long int right = left | 1;
    long long int largest;

    if(left<heapsize && heap[left].b > heap[i].b)
        largest=left;
    else
        largest=i;
    
    if(right<heapsize && heap[right].b > heap[largest].b)
        largest=right;
    
    if(largest!=i){        
        temp=heap[i];
        heap[i]=heap[largest];
        heap[largest]=temp;
        max_heapify(largest);
    }
}

void build_maxheap()
{
    for(long long int i=heapsize/2;i>=1;i--){
        max_heapify(i);
    }
}
void update(long long int i)
{
    heap[i].a-=heap[i].b;
    if(heap[i].a==0)
        heap[i]=heap[--heapsize];
    max_heapify(i);
}
void insert(duo x)
{
    heap[heapsize++]=x;
    long long int i = heapsize-1;
    while(i>1 && heap[i/2].b<heap[i].b)
    {

        temp = heap[i];
        // printf("%lld %lld\n",temp.a,temp.b);
        heap[i]=heap[i/2];
        heap[i/2]=temp;
        i=i/2;
    }
}
void print(long long int d)
{
    for(long long int i=1;i<=d;i++)
    {
        printf("%lld: ",i);
        for(long long int j=0;j<list[i].size();j++)
            printf("%lld,%lld ",list[i][j].a,list[i][j].b);
        printf("\n");
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    long long int t,n,d,di,si,ti;
    for(scanf("%lld",&t);t--;)
    {
        scanf("%lld %lld",&n,&d);
        for(long long int i=1;i<=d+2;i++)
            list[i].clear();
        heapsize=1;
        total_sadness=0;
        for(long long int i=1;i<=n;i++)
        {
            scanf("%lld %lld %lld",&di,&ti,&si);
            duo temp = {ti*si,si};
            total_sadness+=(ti*si);
            list[di].push_back(temp);
        }
        // printf("TestCase: %lld\n%lld\n",t,total_sadness);
        // print(d);
        for(long long int i=1;i<=d;i++)
        {
            // printf("%lld\n",heapsize);
            for(long long int j=0;j<list[i].size();j++)
                insert(list[i][j]);
            if(heapsize>1)
            {
                total_sadness-=heap[1].b;
                update(1);
            }
        }
        
        printf("%lld\n",total_sadness);
    }

    // duo temp1={4,1};heap[1]=temp1;heapsize++;
    // duo temp2={5,5};heap[2]=temp2;heapsize++;
    // duo temp3={3,1};heap[3]=temp3;heapsize++;
    // duo temp4={1,1};heap[4]=temp4;heapsize++;
    // duo temp5={5,1};heap[5]=temp5;heapsize++;
    // build_maxheap();
    // for(long long int i=1;i<heapsize;i++)
    //     printf("%lld,%lld ",heap[i].a,heap[i].b);
    // printf("\n");
    // update(1);
    // for(long long int i=1;i<heapsize;i++)
    //     printf("%lld,%lld ",heap[i].a,heap[i].b);
    // printf("\n");
    // temp.a=8;temp.b=3;
    // insert(temp);
    // for(long long int i=1;i<heapsize;i++)
    //     printf("%lld,%lld ",heap[i].a,heap[i].b);
    // printf("\n");
}