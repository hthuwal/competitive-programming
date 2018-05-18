#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double det(double a[][3])
{
	double p,q,r;
	p = (a[1][1]*a[2][2])-(a[2][1]*a[1][2]);
	q = (a[1][0]*a[2][2])-(a[2][0]*a[1][2]);
	r = (a[1][0]*a[2][1])-(a[2][0]*a[1][1]);
	return a[0][0]*p-a[0][1]*q+a[0][2]*r;
}
double vol(double a[][4])
{
	double b[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=a[i][j]-a[i][3];
		}
	}
	return (det(b))/6;
}
double volfromsidelengths(double ac,double bc,double ab,double bd,double ad,double cd)
{
	double w[3][4];
	w[0][0]=w[1][0]=w[2][0]=0;
	w[0][1]=w[2][1]=0;w[1][1]=ab;
	double x,y,p,q,r;
	y = (ac*ac+ab*ab-bc*bc)/(2*ab);
	x = sqrt(ac*ac-y*y);
	q = (ab*ab+ad*ad-bd*bd)/(2*ab);
	p = (ac*ac+ad*ad-cd*cd-2*q*y)/(2*x);
	r = sqrt(ad*ad-p*p-q*q);
	w[0][2]=x;w[1][2]=y;w[2][2]=0;
	w[0][3]=p;w[1][3]=q;w[2][3]=r;
	return vol(w);
}
int main()
{
	double ab,ac,ad,bc,bd,cd;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>ab>>ac>>ad>>bc>>bd>>cd;
		printf("%0.4f\n",volfromsidelengths(ac,bc,ab,bd,ad,cd));
	}
}
