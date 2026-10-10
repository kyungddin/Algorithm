#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string AEIOU = "AEIOU";

void DFS(
    int len,
    int& count,
    string sentence,
    map<string, int>& dict
)
{
    dict[sentence] = count++;
    
    if (len == 5) return;
    
    for (int i = 0; i < 5; i++)
    {
        DFS(len+1, count, sentence+AEIOU[i], dict);
    }
}

int solution(string word) {
    int answer = 0;
    int count = 1;
    
    map<string, int> dict;
    
    for (int i = 0; i < 5; i++)
    {
        string begin = "";
        begin += AEIOU.at(i);
        DFS(1, count, begin, dict);
    }
    
    answer = dict[word];
    
    return answer;
}