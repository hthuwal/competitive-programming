#include <vector>
#include <map>
using namespace std;
#define vi vector<int>
#define mii map<int,int>

class Solution
{

private:
    int steins_gcd(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;

        // find highest power of 2 that divides both a and b
        int pow;
        for(pow=0; ((a|b)&1)==0; pow++) {
            a >>= 1;
            b >>= 1;
        }

        // make sure a is odd
        while((a&1) == 0) 
            a >>= 1;

        while (true) {
            while ((b&1) == 0) 
                b >>= 1;
            
            if (a > b) {
                int temp = b; b = a; a = temp;
            }

            b = b - a;

            if (b == 0)
                return a<<pow;
        }
    }

    int find_gcd(int a, int b) {
        int temp;
        while (a != 0) {
            temp = a;
            a = b % a;
            b = temp;
        }
        return b;
    }
public:
    bool hasGroupsSizeX(vi &deck)
    {
        mii freqMap = mii();
        for (const auto &card: deck)
            freqMap[card]++;

        vi freqs = vi(freqMap.size());
        for (const auto &map_value: freqMap)
            freqs.push_back(map_value.second);

        if (freqs.size() < 2)
            return false;

        int gcd = steins_gcd(freqs[0], freqs[1]);
        for (const auto &freq: freqs)
            gcd = steins_gcd(gcd, freq);

        if (gcd < 2)
            return false;
        
        return true;
    }
};

int main() {

}