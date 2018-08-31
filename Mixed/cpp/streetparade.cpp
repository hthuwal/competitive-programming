#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int hc[1500]={0},temp[1500]={0},n,j,i,k,flag;
    vector<int> jp;
    while(1)
    {
    cin>>n;
    if(n==0)
        break;
    else
    {
    for(i=0;i<n;i++)
        cin>>temp[i];
    i=1;j=1;
    for(k=0;k<n;k++)
    {
        if(temp[k]==i)
        {
            hc[j]=temp[k];
            j++;
            i++;
        }
        else if(jp.empty()==0 && jp.back()==i)
        {
            hc[j]=jp.back();
            jp.pop_back();
            j++;
            i++;
            k--;
        }
        else
            jp.push_back(temp[k]);
    }
    while(!jp.empty())
    {
        hc[j]=jp.back();
        j++;
        jp.pop_back();
    }
    for(i=1,flag=1;i<j;i++)
    {
        if(hc[i]!=i)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    }
    }
    return 0;
}
