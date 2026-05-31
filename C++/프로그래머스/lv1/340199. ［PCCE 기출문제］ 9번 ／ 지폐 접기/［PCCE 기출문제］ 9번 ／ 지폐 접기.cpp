#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    
    // Variable Setting
    int answer = 0;
    
    // Main Logic
    if(wallet[0] < wallet[1]){
        swap(wallet[0], wallet[1]);
    }
    if(bill[0] < bill[1]){
        swap(bill[0], bill[1]);
    }
    
    while(bill[0] > wallet[0] || bill[1] > wallet[1]){
        bill[0] = bill[0]/2;
        answer++;
        
        if(bill[0] < bill[1]){
            swap(bill[0], bill[1]);
        }
    }
    
    return answer;
}