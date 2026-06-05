#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double n;
    cin >> n;
    double result = n / 4.0;

    cout << fixed << setprecision(2) << result;
    return 0;
}