using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] num_list) {
        Array.Sort(num_list);
        int i = 0;
        while(num_list.Length-i != 5)
        {
            i++;
            Console.WriteLine(i);
        }
        
        return num_list.Take(num_list.Length-i).ToArray();
    }
}