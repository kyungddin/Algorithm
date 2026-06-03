#include <string>
#include <vector>

using namespace std;

bool solution(string sentence) {
    int size = sentence.size();
    
    if (size !=4 && size != 6) 
        return false;
    
    for (auto ch : sentence)
        if ( !isdigit(ch) ) 
            return false;        

    return true;
}