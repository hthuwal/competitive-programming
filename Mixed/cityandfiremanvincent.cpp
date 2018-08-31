/** let say our graph consisits of "m" connected graphs which are mutually disconnected. We need to find the minimum risk value for each of the m graphs and the number of cities in each graph having that minimum risk
That is let the minimum risk in each of the m cities ve Min[1],Min[2],Min[3],.......Min[m] and C[1],C[2],C[3]......C[m] be the count of cities having minimum in each graph
that is in ith graph M[i] is the minimum possible risk and C[i] cities in that graph have M[i] as their risk. So we can choose any one of these C[i] Cities to light that connected graph.
thus total number of ways in which we can light the entire town thati is all the m connected graphs which form the town is
ans  = C[1]*C[2]*C[3].......*C[m]
Since this value can be very high we'll take modulous at every multiplication stage as specified in the quesetion**/

#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#define MOD 1000000007
using namespace std;
vector<long long int>a[10000];
long long int e[10000];
bool isVisited[10000];

/** dfs that would return the total number of nodes(modulo "M" that st count%M) with minimum risk in one connected graph**/

long long int dfs(long long int x){
	long long int temp,i,min,count;
	stack<long long int>hc;
	hc.push(x);
	min=10000;//let this be the minimum risk
	count=1;//number of nodes with the minimum risk

	while(!hc.empty()){
		temp=hc.top();
		isVisited[temp]=1;
		hc.pop();
	/***checking whether this node of the connected graph(jisme abhi hum hain)has the minimum risk***/

		/** if this node has less risk than previous minimum risk this implies new minimum is found.counts of previous minimum are invalid so count mustbe reinitalized to 1. minimum value must be set equal to this new value**/
		if(e[temp]<min){
			min=e[temp];//resetting minimum value
			count=1;//reinitializing the count
		}// if this node has the risk equal to the minimum risk then count of nodes with minimum risk must be incremented*//
		else if(e[temp]==min){
			count++;
		}
	/**Checking complete**/

		/**continuing with dfs**/
		for(i=0;i<a[temp].size();i++){
			if(!isVisited[a[temp][i]]){
				hc.push(a[temp][i]);
			}
		}
	}
	return count%MOD;
}


int main(){
	long long int n,i,k,p,q,ans,temp;
	cin>>n;
	ans=1;
	memset(isVisited,0,10000);
	for(i=0;i<n;i++)
		cin>>e[i];
	cin>>k;
	for(i=0;i<k;i++){
		cin>>p>>q;
		p--;q--;//as the index of node is one based and i am using zero based
		a[p].push_back(q);
		a[q].push_back(p);
	}

	/**  running bfs **/
	for(i=0;i<n;i++)
	{

		if(!isVisited[i])//if the node hasnt been visited do a bfs which would return the count
		{
			temp=dfs(i);
			ans=(ans*temp)%MOD;
		}
	}
	cout<<ans<<endl;
}
