#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end());    
    do
    {
        int hp = k;
        int counter = 0;
        for (int i = 0; i < dungeons.size(); i++)
        {
            if (hp >= dungeons[i][0])
            {
                hp -= dungeons[i][1];
                counter++;
            }
        }
        answer = max(answer, counter);
        
    } while ( next_permutation(dungeons.begin(), dungeons.end()) );
    
    return answer;
}