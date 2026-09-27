#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> numberSet;
    
    for (auto number : phone_book)
    {
        numberSet.insert(number);
    }
    
    for (auto number : phone_book)
    {
        for (int i=1; i<number.size(); i++)
        {
            string substr = number.substr(0, i);
            if(numberSet.find(substr) != numberSet.end())
            {
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}