# BFS vs DFS
```markdown
| 구분    | BFS       | DFS             |
| ----- | --------- | --------------- |
| 방식    | 넓게 탐색     | 깊게 탐색           |
| 자료구조  | 큐         | 스택(또는 재귀)       |
| 최단 경로 | O (무가중치)  | X               |
| 특징    | 거리 계산에 강함 | 경우의 수/구조 분석에 강함 |
```


## BFS(Breadth-First Search)
- Purpose: 완전탐색(Brute Force) + 최단경로(가중치가 없는 경우)

- Implementation: Queue

- Time Complexity: O(V+E)

- Disadvantage: Queue를 사용하므로 메모리를 많이 차지


## DFS(Depth-First Search)
- Purpose: 완점탐색 + 경우의 수 + 백트래킹
    - 경우의 수: 도착지까지 가능한 모든 경로를 찾아줌
    - 백트래킹: 아니다 싶으면 돌아가므로, 알고리즘 자체에 백트래킹 있음

- Implementation: Statk(Recursion)

- Time Complexity: O(V+E)

- Disadvantage: Statck을 사용하므로 오버플로우 가능성 존재
