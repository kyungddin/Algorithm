#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumbers;
    
    for (auto number : numbers)
    {
        strNumbers.push_back(to_string(number));
    }
    
    sort(
        strNumbers.begin(), 
        strNumbers.end(),
        [] (string a, string b) { return a + b > b + a; }
        );
    
    for (auto strNumber : strNumbers)
    {
        answer += strNumber;
    }
    
    if (answer[0] == '0') return "0";
        
    return answer;
}