using System;

public class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = new int[] {};
        
        Array.Sort(num_list);
        Array.Resize(ref answer, num_list.Length-5);
        
        for (int i=0; i < num_list.Length-5; i++)
        {
            answer[i] = num_list[i+5];
        }
        
        return answer;
    }
}