#include <iostream>
#include <ctime>

using namespace std;

void using_cin(int &n)
{
    cin>>n;
}

int main(){
    int i,n;
    
    cout<<"\nUsing Cin with sync_with_stdio(false)\n";
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    clock_t start = clock();
    for(int i=0;i<10000000;i++)
        using_cin(n);
    clock_t stop = clock();
    cout<<"Time taken : "<<((double)(stop-start)/CLOCKS_PER_SEC )<<endl;
}