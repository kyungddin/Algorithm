#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for (auto n : arr)
    {
        if(answer.empty() || answer.back() != n)
            answer.push_back(n);
    }

    return answer;
}