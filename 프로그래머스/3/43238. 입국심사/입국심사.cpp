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
        long long sum = 0;

        for (auto time : times)
        {
            sum += mid / time;
            if (sum >= target) break;
        }
        
        if (sum >= target)
        {
            right = mid - 1;
            answer = mid;
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
    long long maxTime = 0;
    
    auto it = min_element(times.begin(), times.end());
    maxTime = 1LL * n * (*it);
    
    answer = binary_search(0, maxTime, n, times);
    
    return answer;
}