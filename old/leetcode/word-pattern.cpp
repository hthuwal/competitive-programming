#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

class Solution
{
private:
    vector<pair<string,int>> extractPattern(vector<string> sequence)
    {
        string prev = "";
        vector<pair<string,int>> pattern;
        for (const auto &c : sequence)
        {
            if (c != prev)
            {
                pattern.push_back({c, 1});
                prev = c;
            }
            else
            {   
                pattern[pattern.size() - 1].second++;
            }
        }
        return pattern;
    }

public:
    Solution() {

    }
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        stringstream ss = stringstream(s);
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        
        map<char, string> lr;
        map<string, char> rl;
        vector<pair<string, int>> p = extractPattern(words);
        int i = 0;
        for (const auto& count: p) {
            if (i+count.second > pattern.size()) {
                return false;
            }

            char c = pattern[i];
            for (int j=1; j < count.second; j++) {
                if (pattern[i+j] != c) {
                    return false;
                }
            }
            
            if (lr.find(c) == lr.end()){
                lr[c] = count.first;
            } else if (lr[c] != count.first) {
                return false;
            }

            if (rl.find(count.first) == rl.end()) {
                rl[count.first] = c;
            } else if (rl[count.first] != c){
                return false;
            }

            i += count.second;
        }

        if (i != pattern.size()) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    cout << s.wordPattern("abc", "dog cat dog");
}