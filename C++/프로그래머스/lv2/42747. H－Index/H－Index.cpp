#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int cnt = 0;
    
    sort(citations.rbegin(), citations.rend());
    
    for(int i=0; i<citations.size(); i++){
        if(citations[i] >= (cnt+1)){
            cnt++;
        }
        else{
            break;
        }
    }
    
    answer = cnt;
    
    return answer;
}