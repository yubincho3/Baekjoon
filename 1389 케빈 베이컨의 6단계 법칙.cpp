/*
문제에서 요구하는 조건대로 플로이드-워셜 알고리즘을 사용하면 된다. 
*/
#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int n, m, a, b;

int solve(void)
{
	int minVal = INT_MAX, ret;
	
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][k] && arr[k][j])
				{
					arr[i][j] = !arr[i][j] || (arr[i][j] > arr[i][k] + arr[k][j]) ?
								 arr[i][k] + arr[k][j] : arr[i][j];
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
			sum += arr[i][j];
		
		if (minVal > sum)
		{
			minVal = sum;
			ret = i;
		}
	}
	
	return ret;
}

int main(void)
{
	for (scanf("%d %d", &n, &m); m--;)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
	}
	
	printf("%d\n", solve());
	
	return 0;
}

