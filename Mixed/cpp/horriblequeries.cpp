/*Lazy Propagation – An optimization to make range updates faster
When there are many updates and updates are done on a range, we can postpone some updates 
(avoid recursive calls in update) and do those updates only when required.Please remember that a 
node in segment tree stores or represents result of a query for a range of indexes. And if this 
node’s range lies within the update operation range, then all descendants of the node must also 
be updated. For example consider the node with value 27 in above diagram, this node stores sum 
of values at indexes from 3 to 5. If our update query is for range 2 to 5, then we need to update 
this node and all descendants of this node. With Lazy propagation, we update only node with value 27 
and postpone updates to its children by storing this update information in separate nodes called lazy 
nodes or values. We create an array lazy[] which represents lazy node. Size of lazy[] is same as array 
that represents segment tree, which is tree[] in below code.

The idea is to initialize all elements of lazy[] as 0. A value 0 in lazy[i] indicates that there are 
no pending updates on node i in segment tree. A non-zero value of lazy[i] means that this amount needs 
to be added to node i in segment tree before making any query to the node.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define lli long long int
using namespace std;
lli lazy[400000];// To store pending updates

lli create(lli tree[],lli si,lli a[],lli sl,lli sh)
{
	if(sl==sh)
	{
		tree[si]=a[sl];
		return tree[si];
	}
	else
	{
		lli mid = (sl+sh)/2;
		tree[si] = create(tree,2*si,a,sl,mid)+create(tree,2*si+1,a,mid+1,sh);
		return tree[si];
	}
}

lli getsum(lli tree[],lli si,lli sl,lli sh,lli ql,lli qh)
{
	// If lazy flag is set for current node of segment tree,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
	if(lazy[si]!=0)
	{
		// Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
		tree[si]+=(sh-sl+1)*lazy[si];

		// checking if it is not leaf node because if
        // it is leaf node then we cannot go further
		if(sl!=sh)
		{
			// Since we are not yet updating children os si,
            // we need to set lazy values for the children
			lazy[2*si]+=lazy[si];
			lazy[2*si+1]+=lazy[si];
		}

        // unset the lazy value for current node as it has
        // been updated
		lazy[si]=0;
	}
	 // At this point we are sure that pending lazy updates
    // are done for current node. So we can return value 
    // (same as it was for query in our previous post)
 
    // If this segment lies in range
	if(sl>=ql && sh<=qh)
		return tree[si];
	// out of range
	if(ql>sh || qh < sl)
		return 0;

	// If a part of this segment overlaps with the given
    // range
	lli mid=(sh+sl)/2;
	return getsum(tree,2*si,sl,mid,ql,qh)+getsum(tree,2*si+1,mid+1,sh,ql,qh);
}
void update(lli tree[],lli si,lli sl,lli sh,lli i,lli j,lli change)
{
	/* If lazy value is non-zero for current node of segment
     tree, then there are some pending updates. So we need
     to make sure that the pending updates are done before
     making new updates. Because this value may be used by
     parent after recursive calls (See last line of this
     function)
    */
	if(lazy[si]!=0)
	{
		// Make pending updates using value stored in lazy
        // nodes
		tree[si]+=(sh-sl+1)*lazy[si];

		// checking if it is not leaf node because if
        // it is leaf node then we cannot go further
		if(sh!=sl)
		{
			// We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
			lazy[2*si]+=lazy[si];
			lazy[2*si+1]+=lazy[si];
		}
		// Set the lazy value for current node as 0 as it
        // has been updated
		lazy[si]=0;
	}
	// out of range
	if(j<sl || i>sh || sl > sh)
		return;
	// Current segment is fully in range
	if(sl>=i && sh<=j)
	{
		tree[si]+=(sh-sl+1)*change;
		if(sh!=sl)
		{

            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
			lazy[2*si]+=change;
			lazy[2*si+1]+=change;
		}
		return;
	}

	// If not completely in rang, but overlaps, recur for
    // children,
	lli mid=(sl+sh)/2;
	update(tree,2*si,sl,mid,i,j,change);
	update(tree,2*si+1,mid+1,sh,i,j,change);

	// And use the result of children calls to update this
    // node
	tree[si]=tree[2*si]+tree[2*si+1];
}
int main()
{
	lli tree[400000];
	lli a[110000]={0};
	lli t,n,c,r,p,q,v;
	scanf("%lld",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(lazy,0,sizeof(lazy));
		scanf("%lld %lld",&n,&c);
		create(tree,1,a,0,n-1);
		while(c--)
		{
			scanf("%lld %lld %lld",&r,&p,&q);
			p--;q--;
			if(r==0)
			{
				scanf("%lld",&v);
				update(tree,1,0,n-1,p,q,v);
			}
			else if(r==1)
			{
				printf("%lld\n",getsum(tree,1,0,n-1,p,q));
			}
		}
	}
}
	