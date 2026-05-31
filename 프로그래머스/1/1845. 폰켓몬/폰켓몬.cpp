#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int count = 0;
    int size = nums.size();
    
    unordered_map<int, int> hash;
    
    for(int i=0; i<size; i++)
    {
        hash[nums[i]]++;
    }
    
    for(int i=1; i<=200000; i++)
    {
        if(count == size/2) break;
        
        if(hash[i] >= 1)
        {
            answer++;
            count++;
        }
        
        else continue;
    }
    
    return answer;
}