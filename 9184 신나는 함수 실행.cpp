/*
문제에서 제시된 재귀함수를 메모리제이션을 이용해 최적화 하면 된다. 
*/
#include <bits/stdc++.h>
using namespace std;

int dp[21][21][21]; 
int A, B, C;

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	
	if (dp[a][b][c] == 0)
	{
		if (a < b && b < c)
			dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		else
			dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	
	return dp[a][b][c];
}

int main(void)
{
	while (true)
	{
		scanf("%d %d %d", &A, &B, &C);
		
		if (A == -1 && B == -1 && C == -1)
			break;
		
		printf("w(%d, %d, %d) = %d\n", A, B, C, w(A, B, C));
	}
	
	return 0;
}

