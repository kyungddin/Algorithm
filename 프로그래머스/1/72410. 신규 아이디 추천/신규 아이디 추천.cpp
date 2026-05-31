#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string tmp1 = "";
    string tmp2 = "";
    string tmp3 = "";
    string tmp4 = "";
    string tmp5 = "";
    string tmp6 = "";
    string tmp7 = "";
    
    // Step 1: 소문자로 치환
    for (auto c : new_id)
    {
        if( c >= 'A' && c <= 'Z')
            c = tolower(c);
        tmp1 += c;
    }
    
    // Step 2: 문자 제거
    for (auto c : tmp1)
    {
        if (c >= 'a' && c <= 'z')
            tmp2 += c;
        else if(c >= '0' && c <= '9')
            tmp2 += c;
        else if (c == '-')
            tmp2 += c;
        else if (c == '_')
            tmp2 += c;
        else if (c == '.')
            tmp2 += c;
        else
            continue;
    }
    
    // Step 3: . 압축
    
    for (int i=0; i<tmp2.size(); i++)
    {
        if(tmp2[i] == '.')
        {
            if (i == tmp2.size()-1)
            {
                tmp3 += tmp2[i];
            }
            else if(tmp2[i+1] == '.')
                continue;
            else
            {
                tmp3 += tmp2[i];
            }
        }
        else 
        {
            tmp3 += tmp2[i];
        } 
    }
    
    // Step 4 : 시작과 끝의 마침표 제거
    for (int i=0; i<tmp3.size(); i++)
    {
        if (i == 0 && tmp3[i] == '.') continue;
        else if (i == tmp3.size()-1 && tmp3[i] == '.') continue;
        else tmp4 += tmp3[i];
    }
    
    // Step 5 : 빈 문자열에 대해 a를 대입하기
    if (tmp4.size() == 0)
        tmp5 += 'a';
    else
        tmp5 = tmp4;
    
    // Step 6 : 긴 문자를 제거하자
    if (tmp5.size() >= 16)
    {
        tmp6 = tmp5.substr(0, 15);
        
        if(tmp6.back() == '.')
            tmp6 = tmp6.substr(0, 14);
    }
    else
    {
        tmp6 = tmp5;
    }
    
    // Step 7 : 강제 늘리기
    if (tmp6.size() <= 2)
    {
        tmp7 = tmp6;
        while(tmp7.size() != 3)
        {
            tmp7 += tmp7.back();
        }
    }
    else
        tmp7 =tmp6;
    
    return tmp7;
}