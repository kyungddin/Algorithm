/*
Merge_Sort(A, p, r)
if p < r
	q = |(p+r)/2|
	Merge-Sort (A, p, q)
	Merge-Sort (A, q+1, r)
	Merge (A, p, q, r)
*/ 

/*
Merge (A, p, q, r)
n1 = q-p+1
n2 = r-q
let L[1,n1+1], R[1,n2+1] be new arr
for i=1 to n1
	L[i] = A[p+i-1]
for j=1 to n2
	R[j] = A[q+j]
i=1
j=1
for k=p to r
	if i > n1
		A[k] = R[j]
		j++
	else if j > n2
		A[k] = L[i]
		i++
	else if L[i] <= R[j]
		A[k] = L[i]
		i++
	else
		A[k] = R[j]
		j++
*/

#include <iostream>
using namespace std;

long long int result = 0;
int left_arr[500001];
int right_arr[500001];
int a[500001];

void merge_sort(int *arr, int p, int r);
void merge(int *arr, int p, int q, int r);

void merge_sort(int *arr, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

void merge(int *arr, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int i, j;

	for (i = 0; i < n1; i++) {
		left_arr[i] = a[p + i];
	}

	for (j = 0; j < n2; j++) {
		right_arr[j] = a[q + j + 1];
	}

	i = 0; 
	j = 0;

	int k;
	for (k = p; k <= r; k++) {
		if (i >= n1) {
			a[k] = right_arr[j];
			j++;
		}
		else if (j >= n2) {
			a[k] = left_arr[i];
			i++;
		}
		else if (left_arr[i] <= right_arr[j]) {
			a[k] = left_arr[i];
			i++;
		}
		else {
			a[k] = right_arr[j];
			result = result + n1 - i;
			j++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int i;
	int tmp;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		a[i] = tmp;
	}

	merge_sort(a, 0, n-1);

	cout << result;
}