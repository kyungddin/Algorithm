#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    
    // Variable Setting
    int i,j,k;
    int answer = 0;
    
    int friends_num = friends.size();
    map<string, int> friendsIndex;
    
    vector<vector<int>> table(friends_num, vector(friends_num, 0));
    vector<int> TX_count(friends_num, 0);
    vector<int> RX_count(friends_num, 0);
    vector<int> factors(friends_num, 0);
    
    vector<int> result(friends_num, 0);
    
    // Main Logic
    
    for(i=0; i<friends_num; i++){
        friendsIndex[friends[i]] = i;
    }
    
    for(const string &gift : gifts){
        stringstream ss(gift);
        string TX, RX;
        ss >> TX >> RX;
        
        int TX_idx, RX_idx;
        TX_idx = friendsIndex[TX];
        RX_idx = friendsIndex[RX];
        
        table[TX_idx][RX_idx]++;
        TX_count[TX_idx]++;
        RX_count[RX_idx]++;
    }
    
    for(i=0; i<friends_num; i++){
        factors[i] = TX_count[i] - RX_count[i];
    } // 선물지수 계산 로직
    
    for(i=0; i<friends_num; i++){
        for(j=0; j<friends_num; j++){
            if(i==j) continue;
            else{
                if(table[i][j] > table[j][i]) result[i]++;
                else if (table[i][j] == table[j][i]){
                    if(factors[i] > factors[j]) result[i]++;
                }
            }
        }
    }
    
    sort(result.rbegin(), result.rend());
    for(i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    answer = result[0];
    
    return answer;
}