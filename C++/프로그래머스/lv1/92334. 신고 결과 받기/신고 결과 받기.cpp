#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    // Variable Setting
    vector<int> answer;
    
    unordered_map<string, int> report_count = {};
    unordered_map<string, vector<string>> report_list;
    unordered_map<string, bool> ban_list = {};
    
    int i, j;
    
    string TX, RX;
    
    string tmp;
    
    // Overlap Exception
    unordered_map<string, int> map2 = {};
    for(i=0; i<id_list.size(); i++){
        map2[id_list[i]] = i;
    }
    
    bool map3[1001][1001] = {};
    
    // Report Logic
    for(i=0; i<report.size(); i++){
        istringstream ss(report[i]);
        ss >> TX >> RX;
        
        if(map3[map2[TX]][map2[RX]]==0){
            report_count[RX]++;
            report_list[TX].push_back(RX);
            map3[map2[TX]][map2[RX]] = 1;
        }
        else continue;
    }
    
    // Ban Logic
    for(i=0; i<id_list.size(); i++){
        tmp = id_list[i];
        if(report_count[tmp] >= k) ban_list[tmp] = 1;
    }
    
    // Main Logic
    
    int cnt;
    for(i=0; i<id_list.size(); i++){
        cnt = 0;
        tmp = id_list[i];
        for(j=0; j<report_list[tmp].size(); j++){
            if(ban_list[report_list[tmp][j]] == 1) cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}