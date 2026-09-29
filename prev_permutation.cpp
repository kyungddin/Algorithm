#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    vector<int> s{ 1, 2, 3, 4 };
    vector<int> temp{ 1, 1, 0, 0 };
 
    do {
        for (int i = 0; i < s.size(); ++i) {
            if (temp[i] == 1)
                cout << s[i] << ' ';
        }
        cout << endl;
    } while (prev_permutation(temp.begin(), temp.end()));
}
// 4개의 원소 중에서 2개의 원소에 대해 조합을 출력
// prev_permutation 자체가 내림차순으로 동작하므로, temp에 의해 마스킹된 s가 오름차순으로 출력된다
