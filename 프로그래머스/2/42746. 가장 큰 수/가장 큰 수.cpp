#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> vecString;
    
    for (auto num : numbers)
    {
        vecString.push_back(to_string(num));    
    }
    
    sort(vecString.begin(),
         vecString.end(),
         [](const string& a, const string& b)
         {return a+b > b+a ;}
        );
        
    if(vecString[0] == "0") return "0";
    
    for (auto str : vecString)
    {
        answer += str;
    }
    
    return answer;
}