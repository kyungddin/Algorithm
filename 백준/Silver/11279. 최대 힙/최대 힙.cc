#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heap;

void push(int num) {
    heap.push_back(num);
    int child = heap.size() - 1;
    while (child > 0) {
        int parent = (child - 1) / 2;
        if (heap[child] > heap[parent]) {
            swap(heap[child], heap[parent]);
            child = parent;
        }
        else break;
    }
}

int pop() {
    if (heap.empty()) return 0;
    int result = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    int parent = 0;
    int size = heap.size();
    while (true) {
        int left = parent * 2 + 1;
        int right = parent * 2 + 2;
        int largest = parent;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest == parent) break;
        swap(heap[parent], heap[largest]);
        parent = largest;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (num == 0) {
            cout << pop() << "\n";
        }
        else {
            push(num);
        }
    }
    return 0;
}
