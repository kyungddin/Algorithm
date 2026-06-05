#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    cin >> a >> b;
    int limit = (int)sqrt(b);

    vector<int> arr(limit + 1, 0);
    for (int i = 2; i <= limit; i++) {
        arr[i] = i;
    }

    for (int i = 2; i <= limit; i++) {
        if (arr[i] == 0) continue;
        for (int j = i + i; j <= limit; j += i) {
            arr[j] = 0;
        }
    }

    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (arr[i] == 0) continue;

        long long tmp = (long long)arr[i] * arr[i]; 
        while (tmp <= b) {
            if (tmp >= a) count++;
            if (tmp > b / arr[i]) break; 
            tmp *= arr[i];
        }
    }

    cout << count;
    
}
