#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> hashMap;
    
    for (auto message : record)
    {
        istringstream ss(message);
        string token;
        vector<string> parsedMessage;
        
        while (getline(ss, token, ' '))
        {
            parsedMessage.push_back(token);
        }
        
        string result;
        string userName;

        string command = parsedMessage[0];
        string userID = parsedMessage[1];
        
        if (command == "Enter")
        {
            userName = parsedMessage[2];
            hashMap[userID] = userName;
            
            result = userID + "님이 들어왔습니다.";
            answer.push_back(result);
        }
        else if (command == "Leave")
        {
            result = userID + "님이 나갔습니다.";
            answer.push_back(result);
        }
        else if (command == "Change")
        {
            userName = parsedMessage[2];
            hashMap[userID] = userName;
        }
    }
    
    for (auto& str : answer)
    {
        int idx = 0;

        for (int i=0; i < str.size(); i++)
        {
            if( isdigit(str[i]) ) continue;

            else if( isalpha(str[i]) ) continue;

            else
            {
                idx = i;
                break;
            }
        }

        string userID = str.substr(0, idx);
        str.replace(0, idx, hashMap[userID]);
    }
    
    return answer;
}