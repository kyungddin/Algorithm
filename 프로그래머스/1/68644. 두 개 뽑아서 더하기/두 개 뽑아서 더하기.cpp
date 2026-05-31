#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> numSet;
    
    for (int i=0; i<numbers.size()-1; i++)
    {
        for (int j=i+1; j <numbers.size(); j++)
        {
            numSet.insert(numbers[i] + numbers[j]);
        }
    }
    
    for (auto num : numSet)
    {
        answer.push_back(num);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}