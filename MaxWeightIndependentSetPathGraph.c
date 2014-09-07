#include <stdio.h>
#define n 10

int max(int a, int b){
	return a > b ? a : b;
}

int main(void)
{
	int i;
	//Path Graph
	int g[n+1] = {0, 1, 4, 5, 4, 5, 8, 1, 8, 9, 2};

	//Base Cases
	int a[n+1];
	a[0] = 0;
	a[1] = g[1];

	//Main Algorithm
	for (i = 2; i <= n; i++)
		a[i] = max(a[i-1], a[i-2]+g[i]);

	//Result
	printf("%d", a[n]);
	return 0;
}