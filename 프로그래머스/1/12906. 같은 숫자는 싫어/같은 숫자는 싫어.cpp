#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    queue<int> q;
    q.push(arr[0]);
    for(int i=1; i < arr.size(); i++)
    {
        if (arr[i] != q.back()) 
        {
            q.push(arr[i]);
        }
    }
    
    while (!q.empty())
    {
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}