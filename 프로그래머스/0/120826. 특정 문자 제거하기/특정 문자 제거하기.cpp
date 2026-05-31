#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for (auto c : my_string)
    {
        string tmp = "";
        tmp += c;
        
        if (tmp == letter) continue;
        else answer += tmp;
    }
    
    return answer;
}