using System;

public class Solution {
    public int solution(string num_str) {
        int answer = 0;
        
        for (int i=0; i < num_str.Length; i++)
        {
            answer += int.Parse(num_str[i].ToString());
        }
        
        return answer;
    }
}