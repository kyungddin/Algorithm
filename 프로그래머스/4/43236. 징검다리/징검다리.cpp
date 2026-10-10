#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());

    rocks.insert(rocks.begin(), 0);
    rocks.push_back(distance);

    int left = 1;
    int right = distance;
    int answer = 0;

    while (left <= right) 
    {
        int d = left + (right - left) / 2;
        int removed = 0;
        int previous = 0;

        for (int i = 1; i < rocks.size(); ++i) 
        {
            if (rocks[i] - previous < d) 
            {    
                ++removed;
            } 
            else 
            {
                previous = rocks[i];
            }
        }

        if (removed <= n) 
        {
            answer = d;      
            left = d + 1;
        } 
        else 
        {
            right = d - 1;  
        }
    }

    return answer;
}