/*
Calculate area of faces using herons formula and then radius of insphere is a simple formula r=3*v/(a1+a2+a3+a4) 
where v is volume of tetrahedron.. Solve pyramids before this question */
#include <cstdio>
#include <cmath>
double areaoftri(double a,double b,double c)
{
    double s = (a+b+c)/2.0;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}
/**Let the given sides to be u, v, w, W, V, U. Here, (u, U), (v, V), (w, W) \
are considered to be opposite edge pairs ( opposite edges means the edges which 
do not share common vertices ). Now the volume can be found from the following 
formula:
Let:
u′ = v² + w² - U²
v′ = w² + u² - V²
w′ = u² + v² - W²
Now:
volume = 1⁄12 × √(4u²v²w² - u²u′² - v²v′² - w²w′² + u′v′w′)**/
double voloftetra(double a,double A,double b,double B,double c,double C)
{
    double a1 = b*b + c*c - A*A;
    double b1 = c*c + a*a - B*B;
    double c1 = a*a + b*b - C*C;
    return  sqrt(4*a*a*b*b*c*c - a*a*a1*a1 - b*b*b1*b1 - c*c*c1*c1 + a1*b1*c1)/12.0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    double a,b,c,d,e,f,a1,a2,a3,a4,area,volume,r;
    for(scanf("%d",&t);t--;)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
        a1=areaoftri(a,b,d);
        a2=areaoftri(a,c,e);
        a3=areaoftri(d,e,f);
        a4=areaoftri(c,b,f);
        area = a1+a2+a3+a4;
        volume = voloftetra(a,f,b,e,c,d);
        // printf("area is %lf\n",area);
        r = (3*volume)/area;
        printf("%0.4lf\n",r);
    }
}