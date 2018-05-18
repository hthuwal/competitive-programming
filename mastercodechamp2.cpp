#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 
vector<int> list[N]
vector < string > getTolls(int input1,vector < string > input2)
{
	
}

int main() {
    vector < string > output;
    int ip1;
    cin >> ip1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip2_size = 0;
    cin >> ip2_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> ip2;
    string ip2_item;
    for(int ip2_i=0; ip2_i<ip2_size; ip2_i++) {
        getline(cin, ip2_item);
        ip2.push_back(ip2_item);
    }
    output = getTolls(ip1,ip2);
    for(int output_i=0; output_i < output.size(); output_i++) {
    	cout << output[output_i] << endl;;
    }
    return 0;
}
