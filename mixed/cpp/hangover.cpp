    #include<iostream>
    #include<cstdio>
    #include<cmath>
    using namespace std;

    int main()
    {
        float n,ans;
        int i;
        while(1)
        {
            scanf("%f",&n);
            if (n == 0.00)
                break;
            for(i=2,ans=0.00;;i++)
            {
                ans=ans+(1.0/i);
                if(ans>=n)
                    break;
            }
            cout << i-1<<" card(s)"<<endl;
        }
        return 0;
    }
