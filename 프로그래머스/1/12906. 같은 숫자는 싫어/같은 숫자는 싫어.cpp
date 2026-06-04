#include <vector>
#include <algorithm>
std::vector<int> solution(std::vector<int> arr) 
{
    arr.erase(std::unique(arr.begin(), arr.end()),arr.end());
    std::vector<int> answer =  arr;
    return answer;
}