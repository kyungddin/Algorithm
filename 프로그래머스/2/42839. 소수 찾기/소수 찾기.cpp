#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    
    return true;
}

void DFS(
    int r,
    string& numbers,
    vector<char>& picked,
    vector<bool>& visited,
    int& answer,
    map<int, bool>& overlap
)
{
    if (picked.size() == 1 && picked.front() == '0')
    {
        return;
    }
    
    if (picked.size() == r)
    {
        string result = "";
        for (int i = 0; i < r; i++)
        {
            result += picked[i];
        }
        
        int iResult = stoi(result);
        if (isPrime(iResult) && overlap[iResult] == false) 
        {
            cout << iResult << endl;
            overlap[iResult] = true;
            answer++;
        }
        
        return;
    }
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (visited[i] == true) continue;
        
        visited[i] = true;
        picked.push_back(numbers[i]);
        
        DFS(r, numbers, picked, visited, answer, overlap);
        
        visited[i] = false;
        picked.pop_back();
    }
}

int solution(string numbers) {
    int answer = 0;
    
    int size = numbers.size();
    
    vector<char> picked;
    vector<bool> visited(size, false);
    map<int, bool> overlap;
    
    for (int i = 1; i <= size; i++)
    {
        DFS(i, numbers, picked, visited, answer, overlap);
    }
    
    return answer;
}