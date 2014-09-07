#include <stdio.h>
#define m 6
#define n 5

int penalty[4][4] = {{0, 1, 2, 4}, {1, 0, 3, 3}, {2, 3, 0, 2}, {4, 3, 2, 0}};

int min(int a, int b, int c){
	int min;
	min = a < b ? a : b;
	min = min < c ? min : c;
	return min;
}

int mappingPenalty(char a, char b){
	int i, j;
	switch (a){
		case 'A': i = 0;
				break;
		case 'G': i = 1;
				break;
		case 'C': i = 2;
				break;
		case 'T': i = 3;
	}
	switch (b){
		case 'A': j = 0;
				break;
		case 'G': j = 1;
				break;
		case 'C': j = 2;
				break;
		case 'T': j = 3;
	}
	return penalty[i][j];
}

int main(void)
{
	int i, j;

	//Input Data
	char x[m+2] = "0AGGGCT";
	char y[n+2] = "0AGGCA";
	int gapPenalty = 2;

	//Base Cases
	int p[m+1][n+1];
	for (i = 0; i <= m; i++)
		p[i][0] = i*gapPenalty;
	for (j = 0; j <= n; j++)
		p[0][j] = j*gapPenalty;

	//Main Algorithm
	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			p[i][j] = min(p[i-1][j-1]+mappingPenalty(x[i], y[j]), p[i-1][j]+gapPenalty, p[i][j-1]+gapPenalty);
		}
	}

	//Result
	printf("%d", p[m][n]);
	return 0;
}