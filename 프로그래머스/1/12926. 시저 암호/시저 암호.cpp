#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
        for (auto c : s)
        {
            if (c >= 'a' && c<= 'z')
            {
                c = toupper(c);
                c = c + n;
                if (c > 'Z') c = c - 26;
                c = tolower(c);
                
                answer += c;
            }

            else if (c >= 'A' && c <= 'Z')
            {
                c = c + n;
                if (c > 'Z') c = c - 26;

                answer += c;
            }
            else if (c = ' ')
            {
                answer += " ";
            }
        }
    
    return answer;
}