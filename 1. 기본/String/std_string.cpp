#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <format>

using namespace std;

int main()
{
    // 1. 선언 & 입출력
    string s = "Hello World!";
    string sub_s(s, 2, 4);      // substr 초기화

    getline(cin, s);
    getline(cin, s, ',');       // 쉼표전까지만 받아서 저장

    
    // 2. 길이 & 비교
    s.find("ab");               // find()가 못 찾으면 -1 반환
                                // 그러나 find()의 반환 타입은 size_t
                                // (즉, 64bit unsigned 정수형)
                                // 따라서 이것이 -1을 뱉는지는..
                                // string::npos 하고 비교하기


    // 3. 자르기 & 삽입 & 삭제
    s.substr(2, 4);             // 2부터 길이 4
    s.substr(3);                // 3부터 끝까지
    
    s.insert(2, "XY");          // 2앞에 XY 삽입

    s.replace(1, 3, "Z");       // 1부터 3개를 Z로 교체


    // 4. 변환
    to_string(42);              // 숫자 -> 문자열

    stoi(s);                    // 문자열 -> 숫자
    stol(s);
    stof(s);
    stod(s);
    // s[i] - '0'               // 숫자 문자 -> int (빠른 변환)


    // 5. Algorithm
    sort(s.begin(), s.end());               // 오름차순 정렬
    sort(s.begin(), s.end(), greater<>());  // 내림차순 정렬

    reverse(s.begin(), s.end());            // 문자열 뒤집기

    count(s.begin(), s.end(), 'a');         // 특정 문자 개수

    // 중복 제거 (순서 유의)
    sort(s.begin(), s.end());
    auto it = unique(s.begin(), s.end());   // unique 후 쓰레기 위치 it 반환
    s.erase(it, s.end());                   // it 이용해 erase

    // 대소문자 변환
    // ::toupper 이런식으로 std::toupper가 아닌 C의 라이브러리 쓰겠다!
    // C++의 두 변환 함수는 locale이라는 것을 고려하는데, 우리는 그럴 필요 없음
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // 6. 스트림 & 파싱
    // method1 : 공백 기준 분리
    string line1 = "apple banana cherry";
    istringstream ss1(line1);
    string token;
    vector<string> result1;

    while(ss1 >> token)
        result1.push_back(token);

    // method2 : 문자 기준 분리
    string line2 = "apple,banana,cherry";
    istringstream ss2(line2);
    vector<string> result2;

    while(getline(ss2, token, ','))
        result2.push_back(token);

    
    // 7. std::format 활용하기 (C++20)
    cout << format("{} {}", "Hello", "World!");
    printf("%s %s", "Hello", "World!"); // 걍 이게 나을수도..

    return 0;
}


// erase와 substr 더 연습