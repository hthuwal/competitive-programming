/*input
LLRDDR
*/
#include <iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int x=0,y=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='L')
			x--;
		if(s[i]=='R')
			x++;
		if(s[i]=='U')
			y++;
		if(s[i]=='D')
			y--;
	}
	cout<<x<<" "<<y;
}