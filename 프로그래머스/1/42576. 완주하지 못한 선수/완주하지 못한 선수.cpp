#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> hParticipant;
    unordered_map<string, int> hCompletion;
    
    for (auto person : participant)
    {
        hParticipant[person]++;
    }
    
    for (auto person : completion)
    {
        hCompletion[person]++;
    }
    
    for (auto person : participant)
    {
        if(hParticipant[person] != hCompletion[person])
        {
            answer = person;
            break;
        }
    }
    
    return answer;
}