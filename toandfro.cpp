    # include <iostream>
    #include<cstring>
    using namespace std;
    int main()
    {
        int c,l,i,j,k;
        char jp[50][50];
        string hc;
        while(1)
        {
            cin >> c;
            if(c==0)
                break;
            else
            {
                cin >> hc;
                l=hc.length();
                for(i=1,k=0;k<l;i++)
                {
                    if(i%2==1)
                    {
                        for(j=1;j<=c;j++,k++)
                        {
                            jp[i][j]=hc[k];
                        }
                    }
                    else
                    {
                        for(j=c;j>=1;j--,k++)
                        {
                            jp[i][j]=hc[k];
                        }
                    }
                }
            }
            l=i-1;
            for(i=1;i<=c;i++)
            {
                for(j=1;j<=l;j++)
                {
                    cout << jp[j][i];
                }
            }
            cout <<endl;
        }
        return 0;
    }
