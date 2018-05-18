#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void using_cin(int &n)
{
    cin>>n;
}

int main(){
    int i,n;
    
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());

    clock_t start = clock();
    for(int i=0;i<10000000;i++)
        using_cin(n);
    clock_t stop = clock();
    cout<<"Time taken : "<<((double)(stop-start)/CLOCKS_PER_SEC )<<endl;
}