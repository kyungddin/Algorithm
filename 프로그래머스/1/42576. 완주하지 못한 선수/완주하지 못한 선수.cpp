#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> hashP;
    unordered_map<string, int> hashC;
    
    for (int i = 0; i < participant.size(); i++)
    {
        hashP[participant[i]] = 0;
    }
    
    for(int i = 0; i < completion.size(); i++)
    {
        hashC[completion[i]] = 0;
    }
    
    for (int i = 0; i < participant.size(); i++)
    {
        hashP[participant[i]]++;
    }
    
    for(int i = 0; i < completion.size(); i++)
    {
        hashC[completion[i]]++;
    }
    
    for (int i = 0; i < participant.size(); i++)
    {
        if(hashP[participant[i]] != hashC[participant[i]])
        {
            answer = participant[i];
            break;
        }
        else continue;
    }
    
    return answer;
}