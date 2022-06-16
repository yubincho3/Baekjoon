/*
�κ� ���� ���� �ø��� �� �ϳ���.
DP�� �̿��ϴ� ��ǥ���� �ø����� ������.
���� �� �����ϴ� �κ� ����(11053)�� �ݴ�� �˻��ϸ� �ȴ�. 
j > i�� arr[j] > arr[i]�� �����Ҷ�,
dp[i] = max(dp[i], dp[j] + 1)�� ���� ������. 
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

