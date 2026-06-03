#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dictionary;
    
    // Step 1: Init
    int num = 1;
    for(char ch = 'A'; ch <= 'Z'; ch++)
    {
        string alpha(1, ch);
        dictionary[alpha] = num++;
    }
    
    // Step 2: Main Logic
    string cache = "";
    string word = "";
    int length = 1;
    int idx = 0;
    int end = msg.size() + 1;
    
    while(idx + length != end)
    {
        word = msg.substr(idx, length);
        
        if (dictionary[word] != 0)
        {
            cache = word;
            length++;
        }
        else
        {
            answer.push_back(dictionary[cache]);
            dictionary[word] = num++;
            
            cache = "";
            word = "";
            idx = (idx + length - 1);
            length = 1;
        }
    }
    
    // Step 3: Last Word
    if (dictionary[word] != 0)
    {
        cout << word;
        answer.push_back(dictionary[word]);
    }
        
    else
        answer.push_back(num);
    
    return answer;
}