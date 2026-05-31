#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp;
    string result;
    
    // ========================== Logic ==========================
    
    int size = s.size();
    
    for (int i=0; i<size; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            tmp += s[i];
        else
            result += s[i];
        
        if (tmp == "zero")
        {
            result += "0";
            tmp.clear();
        }
        else if (tmp == "one")
        {
            result += "1";
            tmp.clear();
        }
        else if(tmp == "two")  
        {
            result += "2";
            tmp.clear();
        }
        else if (tmp == "three")
        {
            result += "3";
            tmp.clear();
        }
        else if (tmp == "four")
        {
            result += "4";
            tmp.clear();
        }
        else if (tmp == "five") {
            result += "5";
            tmp.clear();
        }
        else if (tmp == "six") {
            result += "6";
            tmp.clear();
        }
        else if (tmp == "seven") {
            result += "7";
            tmp.clear();
        }
        else if (tmp == "eight") {
            result += "8";
            tmp.clear();
        }
        else if (tmp == "nine") {
            result += "9";
            tmp.clear();
        }      
        else
        {
            continue;
        }
    }
    
    answer = stoi(result);
    // ===========================================================
    
    return answer;
}