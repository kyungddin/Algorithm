문자열변수.find("검색할 문자열");
// 성공 : 찾은 하는 문자열의 첫 번째 인덱스 주소 반환한다.
// 실패 : string::npos 를 반환한다.

문자열변수.substr(시작할 위치, 길이);
// 시작할 위치로부터 길이 만큼의 문자열을 잘라낸다.
// 만약 길이를 생략할 경우 문자열의 끝까지 다르게 된다.

문자열변수.append("추가할 문자열");
// 문자열 뒤에 추가

문자열변수.insert(삽입할 위치, "삽입할 문자열");
// 특정 위치에 문자열 삽입

문자열변수.erase(삭제할 위치, 길이);
// 특정 위치의 특정 길이만큼의 문자열 삭제

문자열변수.compare("비교할문자열");
// 문자열 비교 후 Bool 반환
// s.compare(pos, len, s2) 하면 부분 문자열 비교

reverse(문자열변수.begin(), 문자열변수.end());
// 문자열 뒤집기

to_string(int);
// 정수 -> 문자열

toupper() & tolower()
// 대소문자 변환

문자열변수.replace(pos, len, "");
// 부분 문자열 교체

s1.swap(s2);
// 두 문자열 교환

#include <sstream>
vector<string> split(string s, char delimiter) {
    vector<string> result;
    string token;
    stringstream ss(s);
    while (getline(ss, token, delimiter)) result.push_back(token);
    return result;
}
// split 구현하기..
