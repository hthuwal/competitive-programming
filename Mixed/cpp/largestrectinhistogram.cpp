#include<iostream>
#include<stack>
using namespace std;
long long int maxrect(long long int hist[],long long int n)
{
	// Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
	stack<long long int> hc;
	long long int max_area=0;//initialize max sum
	long long int top;//to store the top of stack when popped
	long long int areawithtop,i;	//area with top bar as smallest bar
	
	//run through all bars of given histogram
	i=0;
	while(i<n)
	{
		//if this bar is higher than the bar on top stack, push it to stack
		if(hc.empty()||hist[hc.top()]<=hist[i])
			{
				hc.push(i++);
			}
		// If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left inde			
		else
		{
			top = hc.top();//store the top index
			hc.pop();//pop the top

			//calculate the area wwith hist[top] stack as smallest bar;
			areawithtop = hist[top] * (hc.empty()?i:i-hc.top()-1);

			//update max area,if needed
			if(max_area<areawithtop)
				max_area=areawithtop;
			
		}
	}

	//pop the remaining bars from stack and calculate area with every popped bar 
	//as the smallest bar
	while(!hc.empty())
	{
		top = hc.top();
		hc.pop();
		areawithtop = hist[top] * (hc.empty()?i:i-hc.top()-1);
		if(max_area<areawithtop)
			max_area=areawithtop;
	}
	return max_area;
}
int main()
{
	long long int a[111111],n;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		for(long long int i=0;i<n;i++)
			cin>>a[i];
		cout<<maxrect(a,n)<<endl;
	}
}