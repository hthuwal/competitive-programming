#include<iostream>
using namespace std;
/**
 * find gcd(a,b) and solution of ax+by=gcd(a,b)
 * @param a 
 * @param b
 */
void extendedgcd(int a,int b)
{
	int s = 0;
	int old_s = 1;
	int t = 1;
	int old_t = 0;
	while(b!=0)
	{
		int q = a/b,temp;
		temp = b;
		b = a%b;
		a = temp;

		temp = 	s;
		s =  old_s-q*s;
		old_s = temp;

		temp = 	t;
		t =  old_t-q*t;
		old_t = temp;	
	}
	cout<<"Bezout Coefficients are: "<<old_s<<" "<<old_t<<endl;
	cout<<"gcd is : "<<a<<endl; 
}
int main()
{
	extendedgcd(1,2);
}