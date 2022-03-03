#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t,n,i;
    string hc;
    cin>>t;
    while(t--)
    {
        int jp[8]={0};
        cin>>n;
        cin>>hc;
        for(i=0;i<(hc.length()-2);i++)
        {
            if(hc[i]=='T'&&hc[i+1]=='T'&&hc[i+2]=='T')
                jp[0]++;
            else if(hc[i]=='T'&&hc[i+1]=='T'&&hc[i+2]=='H')
                jp[1]++;
            else if(hc[i]=='T'&&hc[i+1]=='H'&&hc[i+2]=='T')
                jp[2]++;
            else if(hc[i]=='T'&&hc[i+1]=='H'&&hc[i+2]=='H')
                jp[3]++;
            else if(hc[i]=='H'&&hc[i+1]=='T'&&hc[i+2]=='T')
                jp[4]++;
            else if(hc[i]=='H'&&hc[i+1]=='T'&&hc[i+2]=='H')
                jp[5]++;
            else if(hc[i]=='H'&&hc[i+1]=='H'&&hc[i+2]=='T')
                jp[6]++;
            else if(hc[i]=='H'&&hc[i+1]=='H'&&hc[i+2]=='H')
                jp[7]++;
        }
        cout<<n<<" ";
        for(i=0;i<8;i++)
        {
            cout<<jp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
