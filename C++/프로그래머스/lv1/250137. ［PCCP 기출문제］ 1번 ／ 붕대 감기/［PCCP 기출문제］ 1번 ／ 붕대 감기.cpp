#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    // Variable Setting
    int answer = 0;
    
    int i;
    
    int finish_time = attacks.back()[1];
    int present = 0;
    int cnt = 0;
    
    int band_time = bandage[0];
    int band_heal = bandage[1];
    int bonus_heal = bandage[2];
    
    int hp = health;
    
    // Main Logic
    
    sort(attacks.rbegin(), attacks.rend());
    
    while(1){
        present++;
        
        if(attacks.back()[0] == present){
            hp -= attacks.back()[1];
            cnt = 0;
            
            if (hp <= 0){
                answer = -1;
                return answer;
            }
            
            attacks.pop_back();
        }
        
        else{
            hp += band_heal;
            
            if(hp > health) hp = health;
            
            cnt++;
            
            if(cnt == band_time){
                hp += bonus_heal;
                
                if (hp > health) hp = health;
                
                cnt = 0;
            }
        }
        
        if(attacks.empty() == 1) {
            answer = hp;
            break;
        }
    }
    
    return answer;
}