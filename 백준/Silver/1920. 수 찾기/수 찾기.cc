#include <stdio.h>
#include <algorithm>

using namespace std;

int v1[1000000];
int v2[1000000];

bool search(int arr[], int low, int high, int n)
{
	int mid;

	while (low<=high) {
		mid = (low + high) / 2;

		if (arr[mid] == n) return 1;

		else if (arr[mid] < n) {
			low = mid + 1;
		}
		else if (arr[mid] > n) {
			high = mid - 1;
		}
	}

	return 0;
}

int main()
{
	int i, n, m;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &v1[i]);
	}

	sort(v1, v1+n);


	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &v2[i]);
	}

	for (i = 0; i < m; i++)
	{
		printf("%d\n", search(v1, 0, n-1, v2[i]));
	}

}