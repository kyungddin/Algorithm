#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    
    // Variable Setting
    vector<int> answer;
    string n;
    int score;
    unordered_map<string, int> list = {};
    int tmp;
    
    // Labeling
    for(int i=0; i<name.size(); i++){
        n = name[i];
        score = yearning[i];
        list[n] = score;
    }
    
    // Scoring
    for(int i=0; i<photo.size(); i++){
        tmp = 0;
        for(int j=0; j<photo[i].size(); j++){
            tmp += list[photo[i][j]];
        }
        answer.push_back(tmp);
    }
    
    return answer;
}