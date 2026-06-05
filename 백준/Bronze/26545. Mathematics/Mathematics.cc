#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int sum = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }

    cout << sum;
}