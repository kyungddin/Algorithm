#include <string>
#include <vector>

using namespace std;

// n은 벽의 길이
// m은 롤러의 길이
// section은 페인트가 벗겨진 위치
// result는 페인트칠 횟수
// Greedy?
// 1로 번호가 시작함에 유의..!

int solution(int n, int m, vector<int> section) {
    
    // Variable Setting
    int i, j, k;
    int answer = 0;
    vector<int> wall(n+1,1); 
    
    // wall Setting
    for(i=0; i<section.size(); i++){
        wall[section[i]] = 0;
    }
    
    // Painting Time!!
    for(i=1; i<=n; i++){
        if(wall[i]==0){
            while(i+m-1 > n){
                i--;
            }
            for(j=i; j<i+m; j++){
                if(wall[j]==0) wall[j] = 1;
            }
            
            answer++;
        }
    }
    
    return answer;
}