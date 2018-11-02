## [Largest Number](https://www.interviewbit.com/problems/largest-number/)
Given a list of non negative integers, arrange them such that they form the largest number.

```cpp

// yeh hai bc trick
bool comp(string a, string b)
{
    return a+b > b+a;
}

string Solution::largestNumber(const vector<int> &arr) {
    vector<string> hc;
    for(int i=0;i<arr.size();i++)
        hc.push_back(to_string(arr[i]));

    stable_sort(begin(hc), end(hc), comp);
    string ans;
    for(auto each: hc)
        ans += each;
    
    int i;
    for(i=0;i<ans.size()-1;i++)
        if(ans[i] != '0')
            break;
    return string(begin(ans)+i, end(ans));
}
```