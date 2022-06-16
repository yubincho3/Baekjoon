/*
부분 수열 문제 시리즈 중 하나다.
DP를 이용하는 대표적인 시리즈의 문제다.
가장 긴 증가하는 부분 수열(11053)의 반대로 검사하면 된다. 
j > i와 arr[j] > arr[i]를 만족할때,
dp[i] = max(dp[i], dp[j] + 1)의 값을 가진다. 
*/
#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];
int n, ans;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n; j > i; j--)
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
			
		ans = max(ans, dp[i]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}

