#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    
    // Variable Setting
    int i, j;
    int num;
    char key;
    vector<int> answer;
    unordered_map<char, int> map1={};
    
    //Main Logic
    for(i=0; i<keymap.size(); i++){
        for(j=0; j<keymap[i].size();j++){
            key = keymap[i][j];
            map1[key] = 1000;
        }
    }
    
    for(i=0; i<keymap.size(); i++){
        for(j=0; j<keymap[i].size();j++){
            key = keymap[i][j];
            num = j+1;
            
            if(map1[key] > num) {
                map1[key] = num;
                cout << map1[key] << "\n";
            }
        }
    }
    
    int sum = 0;
    bool tf = 0;
    
    for(i=0; i<targets.size(); i++){
        for(j=0; j<targets[i].size(); j++){
            if(map1[targets[i][j]] == 0){
                tf = 1;
            }
            sum += map1[targets[i][j]];
        }
        if (tf == 0){
            answer.push_back(sum);
            sum = 0;
        }
        else{
            answer.push_back(-1);
            tf = 0;
            sum = 0;
        }
    }
    
    return answer;
}