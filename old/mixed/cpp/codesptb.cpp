#include <cstdio>
#define N 111111

int a[N];
int ans=0;
void merge(int l, int mid, int h)
{
	int i=l,j=mid+1,k=0;
	int temp[h-l+1];

	for(;i<=mid && j<=h;)
	{
		if(a[i]<=a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			ans+=(mid-i+1);
		}
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=h)
	{
		temp[k++]=a[j++];
	}
	for(int i=0;i<k;i++)
		a[l+i]=temp[i];
}

void mergesort(int l, int h)
{
	if(l<h)
	{
		int mid = (l+h)>>1;
		mergesort(l, mid);
		mergesort(mid+1, h);
		merge(l,mid,h);
	}
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		mergesort(0,n-1);
		// for(int i=0;i<n;i++)
		// 	printf("%d ",a[i]);
		printf("%d\n",ans);
	}
}n