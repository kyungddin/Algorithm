#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int factorial(int num){
    if (num==1 || num==0) return 1;
    else return (num*factorial(num-1));
}

int comb(int a, int b){
    return factorial(a)/factorial(b)/factorial(a-b);
}

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    // Variable Setting
    int answer = 1;
    unordered_map<string, vector<string>> map1;
    unordered_set<string> set1;
    
    // Map Init
    for(int i=0; i<clothes.size(); i++){
        map1[clothes[i][1]].push_back(clothes[i][0]);
        set1.insert(clothes[i][1]);
    }
    
    for (auto x : set1){
        answer *= (map1[x].size() +1);
    }
    
    answer--;
    
    return answer;
}