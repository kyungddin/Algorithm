#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string buffer;
    string result;
    
    // Step 1: 소문자로 치환
    for (auto ch : new_id)
    {
        if( ch >= 'A' && ch <= 'Z')
            ch = tolower(ch);
        
        buffer += ch;
    }
    result = buffer;
    

    // Step 2: 문자 제거
    buffer = "";

    for (auto c : result)
    {
        if (isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.') 
            buffer += c;
        else
            continue;
    }
    result = buffer;

    // Step 3: . 압축
    buffer = "";
    int size = result.size();

    for (int i = 0; i < size; )
    {
        buffer += result[i];
        if (result[i++] == '.')
            while (result[i] == '.') i++;
    }
    
    result = buffer;
    
    // Step 4 : 시작과 끝의 마침표 제거
    if (result.front() == '.') 
        result.erase(result.begin());
    if (result.back() == '.') 
        result.erase(result.end() - 1);
    
    // Step 5 : 빈 문자열에 대해 a를 대입하기
    if (result.size() == 0) result += 'a';
    
    // Step 6 : 긴 문자를 제거하자
    if (result.size() >= 16)
    {
        result = result.substr(0, 15);
        
        if(result.back() == '.')
            result.erase(result.end() - 1);
    }
    
    // Step 7 : 강제 늘리기
    if (result.size() <= 2)
    {
        while(result.size() != 3)
            result += result.back();
    }
    
    return result;
}