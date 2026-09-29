```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;

pq.push({10, 3});
pq.push({5, 7});
pq.push({20, 1});

auto [cost, node] = pq.top();

// pq는 기본적으로 first를 기준으로 비교
```
