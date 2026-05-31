#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    
    // Variable Setting
    int answer = 0;
    int deadline = 0;
    int i, j, k;
    int tf = 0;
    int hour = 0;
    int minute = 0;
    int t;
    int day;
    
    // Main Logic
    for(i=0; i<schedules.size(); i++){
        t = schedules[i];
        hour = t/100;
        minute = t % 100;
        
        minute += 10;
        if(minute >= 60){
            hour++;
            minute -=60;
        }
        
        hour *= 100;
        deadline = (hour + minute);
        
        for(j=0; j<7; j++){
            day = (startday + j) % 7;
            if(day == 0 || day == 6) continue;
            if(timelogs[i][j] > deadline) tf++;
        }
        
        if (tf > 0) {
            tf = 0;
        }
        
        else{
            answer++;
            tf = 0;
        }
        
    }
    
    return answer;
}