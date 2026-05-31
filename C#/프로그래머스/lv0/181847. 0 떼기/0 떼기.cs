using System;

public class Solution {
    public string solution(string n_str) {
        int idx = 0;
        string answer = "";
        
        for(int i=0; i<n_str.Length; i++)
        {
            if(n_str[i] == '0') continue;
            else {
                answer += n_str[i];
                if(idx != n_str.Length-1) idx = i;
                break;
            }
        }
        
        idx++;
        
        for (int i=idx; i < n_str.Length; i++)
        {
            answer += n_str[i];
        }
        
        return answer;
    }
}