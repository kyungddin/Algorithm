#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[20][20]={};

int solution(int n, int w, int num) {
    
    // 입출력 Acceleration
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // 변수설정
    int answer = 0;
    int count = 0;
    int i;
    int level = 1;
    int p = 1;
    int x, y;
    
    // 상자 쌓기 loop문
    for(i=1; i<=n; i++){
        if (level % 2 == 1){
            arr[p][level] = i;
            
            if(i==num){
                x = p;
                y = level;
            }
            
            if(p == w && i!=n){
                level++;
                continue;
            }
            
            p++;
        }
        else if (level % 2 == 0){
            arr[p][level] = i;
            
            if(i==num){
                x = p;
                y = level;
            }
            
            if(p==1 && i!=n){
                level++;
                continue;
            }
            
            p--;
        }
    } 
    
    // main logic
    for(i=y; i<=level; i++){
        if(arr[x][i] != 0){
            count++;
        }
        else{
            break;
        }
    }
    answer = count;
    
    return answer;
}