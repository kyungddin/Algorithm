#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // Variable Setting
    
    int i;
    int m, s;
    string minute, second;
    string present_cmd;
    
    int v_len = stoi(video_len.substr(0, 2))*60 + stoi(video_len.substr(3,2));
    int p = stoi(pos.substr(0, 2))*60 + stoi(pos.substr(3,2));
    int start = stoi(op_start.substr(0, 2))*60 + stoi(op_start.substr(3,2));
    int end = stoi(op_end.substr(0, 2))*60 + stoi(op_end.substr(3,2));
    
    // Main Logic
    
    for(i=0; i<commands.size(); i++){
        present_cmd = commands[i];
        
        if(p<=end && p>=start){
            p = end;
        }
        
        if(present_cmd == "prev"){
            p -= 10;
            if(p<0){
                p = 0;
            }
        }
        
        else if(present_cmd == "next"){
            p+= 10;
            if(p>v_len) {
                p = v_len;
            }
        }
    }
    
    if(p<=end && p>=start){
        p = end;
    }
    
    m = p / 60;
    s = p % 60;
    
    if(m<10){
        minute = to_string(m);
        minute.insert(0, "0");
    }
    else{
        minute = to_string(m);
    }
    
    if(s<10){
        second = to_string(s);
        second.insert(0, "0");
    }
    else{
        second = to_string(s);
    }
    
    answer.append(minute);
    answer.append(":");
    answer.append(second);
    
    return answer;
}