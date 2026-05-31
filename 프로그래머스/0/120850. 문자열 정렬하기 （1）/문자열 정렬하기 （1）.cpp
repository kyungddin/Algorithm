#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for (auto c : my_string)
    {
        if (c >= '0' && c<='9') 
        {
            int tmp = c - '0';
            answer.push_back(tmp);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}