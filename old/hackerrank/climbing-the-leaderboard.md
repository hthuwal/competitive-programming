## [Climbing the leaderboard](https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem)

```cpp
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    set<int> temp(scores.begin(), scores.end());
    scores = vector<int>(temp.begin(), temp.end());
    
    vector<int> ans;
    
    for(auto each: alice)
    {
        int i = lower_bound(begin(scores), end(scores), each) - begin(scores);
        int rank;
        if(i == scores.size())
            rank = 1;
        else if(scores[i] != each)
            rank = scores.size() - (i - 1);
        else
            rank = scores.size() - i;
        
        ans.push_back(rank);
    }
    
    return ans;
}
```