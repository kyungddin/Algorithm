#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr;
    
    int start_index = 1;
    int end_index = 1;
    int sum = 1;
    
    while (end_index <= 10000)
    {
        if (sum == n)
        {
            answer++;
            end_index++;
            sum += end_index;
        }
        else if (sum < n)
        {
            end_index++;
            sum += end_index;
        }
        else
        {
            sum -= start_index;
            start_index++;
        }
    }
    
    return answer;
}