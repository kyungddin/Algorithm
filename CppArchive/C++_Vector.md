algorihm 헤더 호출 후 swap함수를 쓰면 vector swap이 용이
swap(arr[0], arr[1]); <- 이런식으로다가


2차원 vector를 건드릴때는 무조건 행/열 기준으로 생각하기
vector<vector<int>> dp(n, vector<int>(m, 0));	// 2차원 초기화는 이런식으로..
프로그래머스 공원 문제 잘 풀자..

상하좌우 꿀팁
int dy[4] = {-1, 1, 0, 0}; // y(행)의 변화량 → 상, 하, 좌우 이동 중 세로 이동 담당
int dx[4] = {0, 0, -1, 1}; // x(열)의 변화량 → 좌우 이동 담당
