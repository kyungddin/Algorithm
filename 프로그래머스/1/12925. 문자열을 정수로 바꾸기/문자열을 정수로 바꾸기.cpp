// std::string -> int : std::stoi()
// std::string.substr(startIdx, endIdx)

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.size();
    string tmpString;
    
    if (s[0] == '+')
    {
        tmpString = s.substr(1, size-1);
        answer = stoi(tmpString);
    }
    
    else if (s[0] == '-')
    {
        tmpString = s.substr(1, size-1);
        answer = stoi(tmpString);
        answer = -answer;
    }
    
    else
    {
        answer = stoi(s);
    }
    
    return answer;
}