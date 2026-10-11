#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> double_pq;

void pq_operation(string command, int number)
{
    if (command == "I")
    {
        double_pq.push_back(number);
    }
    else if (command == "D")
    {
        if (!double_pq.empty())
        {
            if (number == 1)
            {
                sort(double_pq.begin(), double_pq.end(), less<int>());
                double_pq.pop_back();
            }
            else if (number == -1)
            {
                sort(double_pq.begin(), double_pq.end(), greater<int>());
                double_pq.pop_back();
            }
        }
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for (auto operation : operations)
    {
        stringstream ss(operation);
        string word;
        vector<string> vec_word;
        
        while (ss >> word)
        {
            vec_word.push_back(word);
        }
        
        pq_operation(vec_word[0], stoi(vec_word[1]));
    }
    
    if (double_pq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        auto max_it = max_element(double_pq.begin(), double_pq.end());
        auto min_it = min_element(double_pq.begin(), double_pq.end());
        
        answer.push_back(*max_it);
        answer.push_back(*min_it);
    }
    
    return answer;
}