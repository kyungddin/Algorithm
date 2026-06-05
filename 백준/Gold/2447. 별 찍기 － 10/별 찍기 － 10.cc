#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> arr;

void draw(int x, int y, int size) {
    if (size == 1) {
        arr[x][y] = '*';
        return;
    }

    int div = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue;
            draw(x + i * div, y + j * div, div);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    arr.assign(N, vector<char>(N, ' '));

    draw(0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}