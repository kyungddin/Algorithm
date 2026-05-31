#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    
    // Variable Setting
    int i, j;
    int answer = -1;
    int max_num = 0;
    int row = park.size();
    int col = park[0].size();
    
    vector<vector<int>> dp;
    
    // Main Logic
    dp.resize(row, vector(col, 0));
    
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(park[i][j] == "-1"){
                if(i==0 || j ==0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                }
                
                max_num = max(max_num, dp[i][j]);
            }
        }
    }
    
    sort(mats.rbegin(), mats.rend());
    for(int mat: mats){
        if(mat <= max_num){
            answer = mat;
            break;
        }
    }
    
    return answer;
}