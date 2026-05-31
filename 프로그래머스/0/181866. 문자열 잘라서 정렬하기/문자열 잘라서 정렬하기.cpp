#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    
    istringstream ss(myString);
    string token;
    
    while ( getline(ss, token, 'x') )
    {
        answer.push_back(token);
    }
    
    sort(answer.begin(), answer.end(), greater<>());
    while(answer.back() == "")
    {
        answer.pop_back();
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}