# BFS는 인접한 vertex를 전부 탐색하며 나아가므로 최단 거리와 같은 문제에 적합하다 (ex: 미로 탐색)
# DFS와는 다르게 queue를 사용한다

# BFS 기본 구현

void BFS(int node){
  queue<int> myqueue;
  myqueue.push_back(node);
  visited[node] = true;

  while(!myqueue.empty()){
    int now_node = myqueue.front();
    myqueue.pop();
    for(int i : A[now_node]){
      if(!visited[i]){
        visited[i] = true;
        myqueue.push(i);
      }
    } // 이렇게 한 노드에 인접한 노드들을 queue안에 전부 때려박아준다
  }
