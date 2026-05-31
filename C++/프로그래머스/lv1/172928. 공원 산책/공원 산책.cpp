#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 동과 서는 그대로
// 첫 배열을 reverse로 뒤집기
// 벗어나는지와 장애물에 대한 예외 케이스 지정

vector<int> solution(vector<string> park, vector<string> routes) {
    
    // Variable Setting
    vector<int> answer;
    vector<int> pos;
    int i, j;
    string dir;
    string tmp;
    int size;
    int H, W;
    
    // Pos Setting
    W = park[0].size();
    H = park.size();
    cout << W << H << "\n";
    
    for(i=0; i<park[0].size(); i++){
        for(j=0; j<park.size(); j++){
            if(park[i][j] == 'S'){
                pos.push_back(i);
                pos.push_back(j);
                cout << pos[0] << pos[1] << "\n";
            }
        }
    }
    
    // Command Setting & Real Move
    for(i=0; i<routes.size(); i++){
        bool tf = 0;
        dir = routes[i].substr(0, 1);
        tmp = routes[i].substr(2, 1);
        size = stoi(tmp);
        
        if(dir == "S"){
            if(pos[0] + size >= H) continue;
            else{
                for(j=pos[0]+1; j<=pos[0]+size; j++){
                    if(park[j][pos[1]] == 'X') {
                        tf = 1;
                        break; 
                    };
                }
                if(tf!=1){
                    pos[0] = pos[0] + size;
                    cout << "S" << "\n";
                }
                else tf = 0;
            }
        }
        else if(dir == "N"){
            if(pos[0] - size < 0) continue;
            else{
                for(j=pos[0]-1; j>=pos[0]-size; j--){
                    if(park[j][pos[1]] == 'X') {
                        tf = 1;
                        break;
                    }
                }
                if(tf!=1){
                    pos[0] = pos[0] - size;
                    cout << "N" << "\n";
                }
                else tf = 0;
            }
        }
        else if(dir == "E"){
            if(pos[1] + size >= W) continue;
            else{
                for(j=pos[1]+1; j<=pos[1]+size; j++){
                    if(park[pos[0]][j] == 'X') {
                        tf = 1;
                        break;
                    }
                }
                if(tf!=1){
                    pos[1] = pos[1] + size;
                    cout << "E" << "\n";
                }
                else tf = 0;
            }
        }
        else if(dir == "W"){
            if(pos[1] - size < 0) continue;
            else{
                for(j=pos[1]-1; j>=pos[1]-size; j--){
                    if(park[pos[0]][j] == 'X') {
                        tf = 1;
                        continue;
                    }
                }
                if(tf!=1){
                    pos[1] = pos[1] - size;
                    cout << "W" << "\n";
                }
                else tf = 0;
            }
        }
        cout << pos[0] << pos[1] << "\n";
    }
    
    answer = pos;
    
    return answer;
}