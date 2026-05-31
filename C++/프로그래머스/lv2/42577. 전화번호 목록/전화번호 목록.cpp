#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    
    // Variable Setting
    bool answer = true;
    unordered_map<string, int> map;
    
    // Initialization
    for(int i=0; i<phone_book.size(); i++){
        map[phone_book[i]]++;
    }
    
    // Main Logic
    for(int i=0; i<phone_book.size(); i++){
        for(int j=1; j<phone_book[i].size(); j++){
            string tmp = phone_book[i].substr(0, j);
            if(map[tmp] == true) answer = false;
        }
    }
    
    return answer;
}