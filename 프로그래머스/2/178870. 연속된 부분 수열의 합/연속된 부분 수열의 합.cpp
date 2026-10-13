#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int size = sequence.size();
    int start_index = 0;
    int end_index = 0;
    int sum = sequence[0];
    int length = INT_MAX;
    int start_result;
    int end_result;
    
    while (end_index != size)
    {
        if (sum == k)
        {
            int arr_length = end_index - start_index + 1;
            
            if (arr_length < length)
            {
                length = arr_length;
                start_result = start_index;
                end_result = end_index;
            }
            
            sum += sequence[++end_index];
        }
        else if (sum < k)
        {
            sum += sequence[++end_index];
        }
        else if (sum > k)
        {
            sum -= sequence[start_index++];
        }
    }
    
    answer.push_back(start_result);
    answer.push_back(end_result);
    
    return answer;
}