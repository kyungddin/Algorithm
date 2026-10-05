#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int numberOne[5] = {1, 2, 3, 4, 5};
    int numberTwo[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int numberThree[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    const int ONE = 5;
    const int TWO = 8;
    const int THREE = 10;
    
    vector<int> result;
    result.push_back(0);
    result.push_back(0);
    result.push_back(0);
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == numberOne[i % ONE]) result[0]++;
        if (answers[i] == numberTwo[i % TWO]) result[1]++;
        if (answers[i] == numberThree[i % THREE]) result[2]++;
    }
    
    vector<pair<int, int>> grade;
    
    for (int i = 0; i < result.size(); i++)
    {
        grade.push_back(make_pair(result[i], i+1));
    }
    
    sort(grade.begin(), grade.end(), [](pair<int, int> a, pair<int, int> b) {return a.first > b.first;});
    
    int max;
    if (grade.front().first != 0) max = grade.front().first;
    
    for (auto n : grade)
    {   
        cout << n.first << endl;
        if(n.first == max && n.first != 0) answer.push_back(n.second);
    }
    sort (answer.begin(), answer.end());
    
    return answer;
}