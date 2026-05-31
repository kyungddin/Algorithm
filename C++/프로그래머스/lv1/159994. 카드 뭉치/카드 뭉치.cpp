#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    
    // Variable Setting
    int i, j;
    string answer = "";
    string word1, word2;
    string tmp;
    deque<string> cards1_d;
    deque<string> cards2_d;
    
    for(i=0; i<cards1.size(); i++){
        cards1_d.push_back(cards1[i]);
    }
    for(i=0; i<cards2.size(); i++){
        cards2_d.push_back(cards2[i]);
    }
    
    // Main Logic
    for(i=0; i<goal.size(); i++){
        tmp = goal[i];
        
        word1 = cards1_d.front();
        word2 = cards2_d.front();
        
        if(word1 == tmp){
            cards1_d.pop_front();
        }
        else if(word2 == tmp){
            cards2_d.pop_front();
        }
        else{
            answer = "No";
            return answer;
        }
    }
    
    answer = "Yes";
    return answer;
}