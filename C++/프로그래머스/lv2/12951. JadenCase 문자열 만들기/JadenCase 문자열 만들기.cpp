#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool newword = true;
    
    for(int i=0; i<s.size(); i++){
        if (s[i] == ' ') newword = true;
        if(newword == true && s[i] != ' '){
            s[i] = toupper(s[i]);
            newword = false;
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    
    answer = s;
    
    return answer;
}