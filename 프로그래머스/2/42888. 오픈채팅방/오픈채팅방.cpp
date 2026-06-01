#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// ================= Case =================
// Enter, Leave, Change
// Muzi 들어옴 -> Prodo 들어옴
// Prodo 들어옴
// Muzi 나감 -> Prodo 나감
// Prodo 들어옴
// ================= Case =================

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string, string> hashMap;
    
    for (auto str : record)
    {
        vector<string> tmpStr;
        istringstream ss(str);
        string token;
        
        while (getline(ss, token, ' '))
        {
            tmpStr.push_back(token);
        }
        
        string userID = tmpStr[1];
        
        if (tmpStr[0] == "Enter")
        {
            hashMap[userID] = tmpStr[2];
            
            userID += "님이 들어왔습니다.";
            answer.push_back(userID);
        }
        else if (tmpStr[0] == "Leave")
        {
            userID += "님이 나갔습니다.";
            answer.push_back(userID);
        }
        else if (tmpStr[0] == "Change")
        {
            hashMap[userID] = tmpStr[2];
        }
    }
    
    for (auto& str : answer)
    {
        int idx = 0;
        for (int i=0; i < str.size(); i++)
        {
            if(str[i] >='0' && str[i] <= 'z') continue;
            else
            {
                idx = i;
                break;
            }
        }
        string ID = str.substr(0, idx);
        str.replace(0, idx, hashMap[ID]);
    }
    
    return answer;
}