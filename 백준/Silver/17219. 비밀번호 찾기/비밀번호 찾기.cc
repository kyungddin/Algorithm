#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> address_pw;

    string address, pw;
    for (int i = 0; i < n; i++) {
        cin >> address >> pw;
        address_pw[address] = pw; 
    }

    for (int i = 0; i < m; i++) {
        cin >> address;
        cout << address_pw[address] << "\n";
    }
}
