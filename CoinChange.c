#include <stdio.h>
#define m 4

int main(void)
{
	int i, j, x, y;

	//Input
	int n = 10;
	int coin[m+1] = {0, 2, 5, 3, 6};

	//Base Cases
	int s[n+1][m+1];
	for (i = 0; i <= n; i++)
		s[i][0] = 0;
	for (j = 0; j <= m; j++)
		s[0][j] = 1;

	//Main Algorithm
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			if (i-coin[j] >= 0)
				s[i][j] = s[i][j-1] + s[i-coin[j]][j];
			else
				s[i][j] = s[i][j-1];
		}
	}

	//Result
	printf("%d", s[n][m]);
	return 0;
}