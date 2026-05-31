# DFS는 깊이우선으로 탐색하며, 완전 탐색 상황에서 적합하다 (가능한 모든 경우 탐색)
# 스택을 이용할 수도 있으나, 보통 재귀를 이용해 구현한다
# 최대깊이까지 갔다가 돌아와서 다른 경로로도 가므로 백트래킹과도 관련이 있다

# DFS 기본 구현
# 방문을 체크할 리스트와, 그래프를 표현할 인접리스트가 필요하다

void DFS(int v){
  if(visited[v]) return;

  visited[v] = true;

  for (int i : A[v]){
    if(visited[i] == false){
      DFS(i);
    }
  }
}
