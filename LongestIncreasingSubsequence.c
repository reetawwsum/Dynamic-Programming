#include <stdio.h>
#define n 9

int main(void){
	int i, j, max;

	//Input
	int a[n+1] = {0, 10, 22, 9, 33, 21, 50, 41, 60, 80};

	//Base Cases
	int l[n+1];
	for (i = 1; i <= n; i++)
		l[i] = 1;

	//Main Algorithm
	for (i = 2; i <= n; i++){
		for (j = 1; j < i; j++){
			if (a[i] > a[j] && l[j]+1 > l[i])
				l[i] = l[j] + 1;
		}
	}
	max = l[1];
	for (i = 2; i <= n; i++)
		max = l[i] > max ? l[i] : max;

	//Result
	printf("%d", max);
	return 0;
}