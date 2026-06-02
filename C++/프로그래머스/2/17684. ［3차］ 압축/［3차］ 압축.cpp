#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> hashMap;

    // 1. Initialization
    int idx = 1;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        string tmp = "";
        tmp += c;
        hashMap[tmp] = idx;
        idx++;
    }

    // 2. Main Event
    string subStr;
    string prevStr;
    int cache = 0;
    int length = 1;

    for (int i = 0; i < msg.size(); )
    {
        if (i + length > msg.size())
        {
            answer.push_back(cache);
            break;
        }

        subStr = msg.substr(i, length);

        if (hashMap[subStr] > 0)
        {
            cache = hashMap[subStr];
            length++;
        }

        else if (hashMap[subStr] == 0)
        {
            answer.push_back(cache);
            hashMap[subStr] = idx++;

            i = i + length - 1;
            length = 1;
        }

    }

    return answer;
}