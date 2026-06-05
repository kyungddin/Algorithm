#include <stdio.h>

int main()
{
	int n, a, b, r, ans, f;
	int i;
	int x, y;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		x = a > b ? a : b;
		y = a > b ? b : a;

		while (1) {
			r = x % y;
			if (r == 0) break;
			x = y;
			y = r;
		}
		f = a * b / y;
		printf("%d\n", f);
	}
}