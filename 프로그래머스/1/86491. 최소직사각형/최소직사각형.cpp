#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;
    
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][1] > sizes[i][0])
        {
            int tmp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = tmp;
        }
    }
    
    int maxW = INT_MIN;
    int maxH = INT_MIN;
    
    for (auto size : sizes)
    {
        int W = size[0];
        int H = size[1];
        
        if (W > maxW) maxW = W;
        if (H > maxH) maxH = H;
    }
    
    answer = maxW * maxH;
    
    return answer;
}