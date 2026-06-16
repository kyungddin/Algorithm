#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> subarr;
    
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> curCommand = commands[i];
        subarr.clear();
        for (int j = curCommand[0] -1 ; j < curCommand[1]; j++)
        {
            subarr.push_back(array[j]);
        }
        sort(subarr.begin(), subarr.end());
        answer.push_back(subarr.at(curCommand[2]-1));
    }
    
    
    return answer;
}