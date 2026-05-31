#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    
    // Variable Setting
    int i, j, k;
    vector<int> answer;
    int ymin = 100;
    int ymax = -1;
    int xmin = 100;
    int xmax = -1;
    int H = wallpaper.size();
    int W = wallpaper[0].size();
    
    // Main Logic
    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            if(wallpaper[i][j] == '#'){
                if (i < ymin) ymin = i;
                if (i > ymax) ymax = i;
                if (j < xmin) xmin = j;
                if (j > xmax) xmax = j;
            }
        }
    }
    
    xmax++;
    ymax++;
    
    answer.push_back(ymin);
    answer.push_back(xmin);
    answer.push_back(ymax);
    answer.push_back(xmax);
    
    return answer;
}