#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> land)
{
    // Variable Setting
    int i, j, k;
    int answer = 0;
    int max = 0;
    int sum = 0;
    
    vector<vector<int>> dp;
    dp = land;
    
    // Exception
    if(dp.size() == 1){
        sort(dp[0].rbegin(), dp[0].rend());
        answer = dp[0][0];
        return answer;
    }

    // Main Logic
    for(i=1; i<dp.size(); i++){
        for(j=0; j<4; j++){
            for(k=0; k<4; k++){
                if(j == k) continue;
                
                else{
                    sum = dp[i][j] + dp[i-1][k];
                    if (sum > max) {
                        max = sum;
                    }
                }
            }
            dp[i][j] = max;
            max = 0;
        }
    }
    
    int n = dp.size();
    sort(dp[n-1].rbegin(), dp[n-1].rend());
    answer = dp[n-1][0];

    return answer;
}