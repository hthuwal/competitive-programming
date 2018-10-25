### [Super Reduced String](https://www.hackerrank.com/challenges/reduced-string/problem)

```cpp
string superReducedString(string s) {
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        int count = 0;
        while(!st.empty() and st.top() == s[i])
        {
            count++;
            st.pop();
        }
        if(count == 0)
            st.push(s[i]);
    }
    string ans = "";
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    if(ans == "")
        return "Empty String";
    else
        return string(ans.rbegin(), ans.rend());
}
```

### [Camel Case](https://www.hackerrank.com/challenges/camelcase)

```cpp
int camelcase(string s) {
    int cnt=1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] <= 'Z' and s[i]>='A')
            cnt++;
    }
    return cnt;
}
```

---

### [Strong Password](https://www.hackerrank.com/challenges/strong-password)

```python
def minimumNumber(n, password):
    conditions = [0] * 4
    for each in password:
        if each in numbers:
            conditions[0] += 1
        if each in lower_case:
            conditions[1] += 1
        if each in upper_case:
            conditions[2] += 1
        if each in special_characters:
            conditions[3] += 1
        
    unmet_conditions = Counter(conditions)[0]
    print(conditions)
    if n + unmet_conditions >= 6:
        return unmet_conditions
    else:
        return 6-n
```

### [Mars Exploration](https://www.hackerrank.com/challenges/mars-exploration/problem)


```python
def marsExploration(s):
    ans = 0
    for i in range(0, len(s), 3):
        if(s[i] != 'S'):
            ans += 1
        if(s[i+1] != 'O'):
            ans += 1
        if(s[i+2] != 'S'):
            ans += 1
    return ans
```

### [HackerRank in a String]()

```python
def hackerrankInString(s):
    x = "hackerrank"
    j = 0
    for c in s:
        if (c==x[j]):
            j += 1
            if(j == len(x)):
                return "YES"
    return "NO"
```

### [Panagrams](https://www.hackerrank.com/challenges/pangrams/problem)

```cpp
string pangrams(string s) {
    int hc_hash[26]={0};
    for(int i=0;i<s.length();i++)
    {
        hc_hash[tolower(s[i])-'a']++;
    }
    for(int i=0;i<26;i++)
        if(hc_hash[i]==0)
            return "not pangram";
    return "pangram";
}
```