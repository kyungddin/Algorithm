#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> pos;
    vector<string> answer;
    int tmp;
    
    for(int i=0; i<players.size();i++){
        pos[players[i]] = i;
    }
    
    for(int i=0; i<callings.size(); i++){
        tmp = pos[callings[i]];
        
        swap(players[tmp], players[tmp-1]);
        
        pos[players[tmp]] = tmp;
        pos[players[tmp-1]] = tmp-1;
    }
    
    for(int i=0; i<players.size(); i++){
        answer.push_back(players[i]);
    }
    
    return answer;
}