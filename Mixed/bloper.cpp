/** dp solution giving tle try some greedy approach */
#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>, string> dp;
string recursive(int n, int x){
	string a,b;

	if (dp.count(make_pair(n, x)) != 0)
		return dp[make_pair(n, x)];

	if(x>0 && ((n*(n+1)) / 2) < x){
		// cout<<"x:"<<x<<" n:"<<n<<" Impossible\n";
		dp[make_pair(n, x)] = "Impossible";
		return "Impossible";
	}

	if(x<0 && ((n*(n+1)) / 2)-1 > (-x)){
		// cout<<"x:"<<x<<" n:"<<n<<" Impossible\n";
		dp[make_pair(n, x)] = "Impossible";
		return "Impossible";
	}

	if(n == 1){
		if(x == 1){
			// cout<<"x:"<<x<<" n:"<<n<<" 1\n";
			dp[make_pair(n, x)] = "1";
			return "1";
		}
		else{
			// cout<<"x:"<<x<<" n:"<<n<<" Impossible\n";
			dp[make_pair(n, x)] = "Impossible";
			return "Impossible";
		}
	}
	else{
		a = recursive(n-1, x-n);
		b = recursive(n-1, x+n);

		// cout<<"a: "<<a<<" b:"<<b<<" x:"<<x<<" n:"<<n;
		// getchar();
		if(a != "Impossible"){
			// cout<<" yO\n";
			dp[make_pair(n, x)] = a + "+" + to_string(n);
			return a + "+" + to_string(n);
		}
		if(b != "Impossible"){
			// cout<<" jo\n";
			dp[make_pair(n, x)] = b + "-" + to_string(n);
			return b + "-" + to_string(n);
		}
		// cout<<" hai\n";
		dp[make_pair(n, x)] = "Impossible";
		return "Impossible";
	}
}
int main()
{
	int n, t;
	freopen("in.txt", "r", stdin);
	scanf("%d %d",&n, &t);
	cout<<recursive(n, t)<<"\n";
}