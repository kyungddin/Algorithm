#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    
    // Variable Setting
    int i, j, k;
    string answer = "";
    unordered_map<char, bool> map1 = {};
    
    // Main Logic
    for(i=0; i<skip.size(); i++){
        map1[skip[i]] = 1;
    }
    
    for(i=0; i<s.size(); i++){
        for(j=0; j<index; j++){
            s[i]++;
            if(s[i] == 'z'+1) s[i] = 'a';
            while(map1[s[i]]==1) {
                s[i]++;
                if(s[i] == 'z'+1) s[i] = 'a';
            }
        }
    }
    
    answer = s;
    
    return answer;
}