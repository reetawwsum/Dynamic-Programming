#include <stdio.h>
#define m 6
#define n 7

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, j;

	//Input
	char x[m+2] = "0AGGTAB";
	char y[n+2] = "0GXTXAYB";

	//Base Cases
	int l[m+1][n+1];
	for (i = 0; i <= m; i++)
		l[i][0] = 0;
	for (j = 0; j <= n; j++)
		l[0][j] = 0;

	//Main Algorithm
	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			if (x[i] == y[j])
				l[i][j] = 1+l[i-1][j-1];
			else
				l[i][j] = max(l[i-1][j], l[i][j-1]);
		}
	}

	//Result
	printf("%d", l[m][n]);
	return 0;
}