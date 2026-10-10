#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long binary_search(long long left, long long right, long long target, vector<int>& times)
{
    long long answer = right;
    
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long result = 0;
        
        for (auto time : times)
        {
            result += static_cast<long long>(mid / time);
        }

        if (result >= target)
        {
            answer = mid;
            right = mid - 1;
            
        }
        else
        {
            left = mid + 1;
        }
    }   
    
    return answer;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long maxTime = 1LL * (*(min_element(times.begin(), times.end()))) * n;
    
    answer = binary_search(0, maxTime, n, times);
    
    return answer;
}