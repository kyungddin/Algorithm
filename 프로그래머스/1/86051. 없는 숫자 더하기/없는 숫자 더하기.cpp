#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end(), greater<>());
    
    int i = 0;
    while(true)
    {
        if( numbers.back() != i) 
        {
            answer += i;
            i++;
        }
        else
        {
            numbers.pop_back();
            i++;
        }
        
        if (i == 10) break;
        
    }
    
    return answer;
}