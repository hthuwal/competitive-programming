### two-city-scheduling

[Problem](https://leetcode.com/problems/two-city-scheduling)

### Go Solution

- Took: 0 ms 🤷‍♂️ and 2.5 MB

```go
func twoCitySchedCost(costs [][]int) int {
    sort.Slice(costs, func(i, j int) bool{
        idiff := costs[i][0] - costs[i][1]
        jdiff := costs[j][0] - costs[j][1]
        return idiff < jdiff
    })
    
    cost := 0
    for i := 0; i < len(costs) / 2; i++ {
        cost += costs[i][0]
    }

    for i := len(costs) / 2; i < len(costs); i++ {
        cost += costs[i][1]
    }
    return cost
}
```


### Cpp Solution

- Took about: 8 ms and 7.8 MB

```cpp
class Solution {
public:
    bool static compare(vector<int> &v1, vector<int> &v2) 
    { 
        return (v1[0]-v1[1]) < (v2[0]-v2[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare);
        int cost = 0;
        for (int i=0;i<costs.size()/2;i++)
            cost += costs[i][0];
        for (int i=costs.size()/2; i< costs.size();i++)
            cost += costs[i][1];
        return cost;
    }
};
```

### Python Solution

- Took about: 50 ms and 13.8 MB

```python
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda x: x[0] - x[1])
        return sum(map(lambda y: y[0], costs[0:len(costs)//2])) + sum(map(lambda y: y[1], costs[len(costs)//2:]))
```