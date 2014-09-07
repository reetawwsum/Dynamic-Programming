#include <stdio.h>
#define n 4

int max(int a, int b){
	return a > b ? a : b;
}

int main(void)
{
	int i, x;

	//N items with values and weights
	int v[n+1] = {0, 3, 2, 4, 4};
	int w[n+1] = {0, 4, 3, 2, 3};
	int W = 6;

	//Base Cases
	int a[n+1][W+1];
	for (x = 0; x <= W; x++)
		a[0][x] = 0;

	//Main Algorithm
	for (i = 1; i <= n; i++){
		for (x = 0; x <= W; x++){
			if (x-w[i] < 0)
				a[i][x] = a[i-1][x];
			else
				a[i][x] = max(a[i-1][x], v[i]+a[i-1][x-w[i]]);
		}
	}

	//Result
	printf("%d", a[n][W]);
	return 0;
}