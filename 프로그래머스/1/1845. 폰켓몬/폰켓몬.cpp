#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    set<int> ponketmon;
    
    for (auto n : nums)
    {
        ponketmon.insert(n);
    }
    
    int halfSize = nums.size() / 2;
    int size = ponketmon.size();
    
    if (halfSize > size)
    {
        answer = size;
    }
    else
    {
        answer = halfSize;
    }
    
    return answer;
}