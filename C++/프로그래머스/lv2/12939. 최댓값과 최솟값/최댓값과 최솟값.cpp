#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;

string solution(string s) {
    string answer = "";
    string tmp;
    vector<string> mem;
    vector<int> result;
    stringstream ss(s);
    
    while(getline(ss, tmp, ' ')){
        mem.push_back(tmp);
    } // 공백에 따른 파싱
    
    for(int i=0; i<mem.size(); i++){
        result.push_back(stoi(mem[i]));
    }
    
    sort(result.begin(), result.end());
    
    answer += to_string(result.front());
    answer += " ";
    answer += to_string(result.back());
    
    return answer;
}