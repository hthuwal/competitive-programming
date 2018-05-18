#include <cstdio>
#include <cmath>
double pi = atan(1)*4;
double fx(int R, int H, double h)
{
    double L = sqrt(R*R + H*H); // slant height of hat

    double r = (h/H)*R; // radius of filled cone
    double l = (h/H)*L; // slant height of filled cone

    double area = 2*R*L - r*l; // area to be painted
    double volume = (1.0/3)*r*r*h;
    return area-volume;
}
double height(int R, int H)
{
    double l = 0;
    double e = H;
    double h;
    while(l<e)
    {
        h = (l+e)/2;
        double x = fx(R,H,h);
        if((fabs(x)<0.0000001))
            return h;
        else if(x < 0)
            e = h;
        else
            l = h;
    }
    return H;
}
int main()
{
    int t,R,H;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&R, &H);
        printf("%lf\n",height(R,H));
    }
}