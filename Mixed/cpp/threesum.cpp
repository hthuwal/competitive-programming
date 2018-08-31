#include<bits/stdc++.h>
using namespace std;
vector<int>cubes;
int main()
{
    long long int hc,i,n,a[550],t,cube,total,p,b,c,d,e,j,k;
    double ans;
    for(i=1;;i++)
    {
        hc=i*i*i;
        if(hc<=6600)
            cubes.push_back(i*i*i);
        else
            break;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        total=0;
        for(p=0;p<cubes.size();p++)
        {
            cube=cubes[p];

            sort(a,a+n);
            for(i=0;i<n-1;i++)
            {
                j=i+1;
                k=n-1;
                while(j<k)
                {
                    if(a[i]+a[j]+a[k]==cube)
                    {
                        if(a[j]!=a[k])
                        {
                        b=1;
                        c=1;
                        d=j+1;
                        e=k-1;

                        while(d<k)
                        {
                            if(a[d]==a[j])
                                b++;
                            d++;
                        }
                        while(e>j)
                        {
                            if(a[e]==a[k])
                                c++;
                            e--;
                        }
                        total+=(b*c);
                        }
                        else
                        {
                            b=(k-j+1);
                            total+=((b*(b+1))/2);
                        }
                        break;
                    }
                    else if(a[i]+a[j]+a[k]<cube)
                        j++;
                    else
                        k--;
                }
            }
        }

        ans=double(total*2*3)/(n*(n-1)*(n-2));
        printf("%0.9f\n",ans);
    }
}
