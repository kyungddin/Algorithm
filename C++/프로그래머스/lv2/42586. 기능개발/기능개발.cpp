#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    // Variable Setting
    vector<int> answer;
    deque<pair<int, int>> q;
    int cnt = 0;
    
    // Queue INIT
    for(int i=0; i<progresses.size(); i++){
        q.push_back(make_pair(progresses[i], speeds[i]));
    }
    
    // Main Logic
    while(!q.empty()){
        cnt = 0;
        
        // day ++
        for(int i=0; i<q.size(); i++){
            if(q[i].first < 100) q[i].first+=q[i].second;
            if(q[i].first >= 100) q[i].first = 100;
        }
        
        // pop loop
        while(q.front().first == 100){
            cnt++;
            q.pop_front();
        }
        
        if(cnt != 0){
            answer.push_back(cnt);
        }
    }
    
    return answer;
}