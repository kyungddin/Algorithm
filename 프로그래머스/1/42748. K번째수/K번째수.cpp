#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto command : commands)
    {
        int start = command[0] - 1;
        int end = command[1];
        int pos = command[2] - 1;
        
        vector<int> subvec(array.begin() + start, array.begin() + end);
        
        sort(subvec.begin(), subvec.end());
        
        answer.push_back(subvec[pos]);
    }
    
    return answer;
}