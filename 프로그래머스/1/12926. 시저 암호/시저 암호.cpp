#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ALPHA_SIZE 26

string solution(string sentence, int num) {
    string answer = "";
    
        for (auto ch : sentence)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                ch = toupper(ch) + num;
                if (ch > 'Z') ch -= ALPHA_SIZE; // Circular Shift
                ch = tolower(ch);
                
                answer += ch;
            }

            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + num;
                if (ch > 'Z') ch -= ALPHA_SIZE;

                answer += ch;
            }
            else
            {
                answer += " ";
            }
        }
    
    return answer;
}