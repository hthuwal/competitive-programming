	#include<iostream>
	#include<cstdio>
	using namespace std;
	/*
		let node denotes some segment sl to sh then
		start => the maximum sum from all subarrays starting at sl
		end => the maximum sum from all subarrays ending at sh
		ans => masimum sum from all possible subarrays
		total => sum  of the entire  segment
	*/
	struct node{
		long int start;
		long int end;
		long int ans;
		long int total;
	};

	node tree[10000000];

	/*function to initialize a node*/
	void initialize(node *x,int v)
	{
		(*x).ans=v;
		(*x).start=v;
		(*x).end=v;
		(*x).total=v;
	}
	/*function to find maximum of three numbers*/
	int max(long int a,long int b,long int c)
	{
		if(a>b)
		{
			if(a>c)
				return a;
			else
				return c;
		}
		else
		{
			if(b>c)
				return b;
			else
				return c;
		}
	}
	/*max of two numbers*/
	int max(long int a,long int b)
	{
		return a>b?a:b;
	}

	node create(node tree[],int si,int a[],int sl,int sh)
	{
		if(sl==sh)//if the segment is only a single element
		{
			tree[si].ans=a[sl];
			tree[si].start=a[sl];
			tree[si].end=a[sl];
			tree[si].total=a[sl];		
			return tree[si];
		}
		else
		{
			int mid=(sl+sh)/2;//splitting the segment
			node left,right;
			
			left=create(tree,2*si,a,sl,mid);
			right=create(tree,2*si+1,a,mid+1,sh);
			
			tree[si].ans=max(left.ans,left.end+right.start,right.ans);//max sum wali subarray either lies entirely in left, or entirely in right or in both
			tree[si].start=max(left.start,left.total+right.start);
			tree[si].end=max(right.end,right.total+left.end);
			tree[si].total=left.total+right.total;
			return tree[si];
		}
	}
	node getans(node tree[],int sl,int sh,int si,int ql,int qh)
	{
		if(ql<=sl && qh>=sh)
			return tree[si];
		node ret;
		initialize(&ret,-16000);
		
		if(sl>qh || sh<ql)
		{
			return ret;
		}

		int mid=(sl+sh)/2;
		node left,right;
		left = getans(tree,sl,mid,2*si,ql,qh);
		right = getans(tree,mid+1,sh,2*si+1,ql,qh);

		ret.ans=max(left.ans,left.end+right.start,right.ans);
		ret.start=max(left.start,left.total+right.start);
		ret.end=max(right.end,right.total+left.end);
		ret.total=left.total+right.total;

		return ret;
	}

	int main()
	{
		int a[55000],n,x,y,m;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		create(tree,1,a,0,n-1);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d %d",&x,&y);
			x--;y--;
			printf("%ld\n",getans(tree,0,n-1,1,x,y).ans);
		}
	}		