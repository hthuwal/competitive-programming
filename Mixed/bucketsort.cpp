#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
void bucketSort(vector<int> a)
{
	int n=a.size();
	vector<int> b[n+1];
	int max=a[0];
	int min=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
	double interval = n/(max-min);
	for(int i=0;i<n;i++)
	{
		int j = (int)(a[i]-min)*interval;
		b[j].push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		sort(b[i].begin(),b[i].end());
	}
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<b[i].size();j++){
			cout<<b[i][j]<<" ";
		}
	}
	int i =INT_MIN;
}
int main(){
	int a[]={4,8,4,1,9,4,2,1};
	vector<int>hc(a,a+sizeof(a)/sizeof(int));
	bucketSort(hc);
}