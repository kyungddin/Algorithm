using System;

public class Solution {
    public int solution(int n, string control) {
        int answer = 0;
        
        for (int i=0; i<control.Length; i++)
        {
            if (control[i] == 'w') n += 1;
            else if (control[i] == 's') --n;
            else if (control[i] == 'd') n+=10;
            else n -= 10;
        }
        
        answer = n;
        return answer;
    }
}