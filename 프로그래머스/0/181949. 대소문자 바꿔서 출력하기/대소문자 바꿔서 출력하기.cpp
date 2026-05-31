#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string answer = "";
    string str;
    cin >> str;
    
    for (auto c : str)
    {
        if (c >= 'a' && c<= 'z') c = toupper(c);
        else c = tolower(c);
        
        string tmp = "";
        tmp += c;
        
        answer += tmp;
    }
    
    cout << answer;
    
    return 0;
}