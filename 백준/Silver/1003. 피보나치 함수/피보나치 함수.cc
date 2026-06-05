#include <iostream>
using namespace std;

pair<int, int> table[41];

void build_table() {
    table[0] = { 1, 0 }; 
    table[1] = { 0, 1 };
    for (int i = 2; i <= 40; i++) {
        table[i].first = table[i - 1].first + table[i - 2].first;
        table[i].second = table[i - 1].second + table[i - 2].second;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    build_table();

    int n, tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        cout << table[tmp].first << " " << table[tmp].second << "\n";
    }
    return 0;
}
