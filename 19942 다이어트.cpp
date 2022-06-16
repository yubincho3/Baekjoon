/*
모든 경우의 수를 전부 조합해서 최솟값을 찾기만 하면 되는 간단한 백트래킹 문제다. 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> minSelected;
vector<int> selected;
int arr[16][5];
int mpfsv[4];
int pfsv[4];
int n, ans = -1;

void func(int idx)
{
	if (idx == n)
	{
		if (selected.size() == 0)
			return;
		
		for (int i = 0; i < 4; i++)
			if (pfsv[i] < mpfsv[i])
				return;
			
		int sum = 0;
		for (int temp : selected)
			sum += arr[temp][4];
			
		if (ans == sum)
		{
			string s1, s2;
			
			for (int temp : minSelected)
				s1 += (char)(temp + '0');
			for (int temp : selected)
				s2 += (char)(temp + '0');
				
			if (s1 > s2)
				minSelected = selected;
		}
		if (ans == -1 || ans > sum)
		{
			minSelected = selected;
			ans = sum;
		}
		
		return;
	}
	
	selected.push_back(idx);
	for (int i = 0; i < 4; i++)
		pfsv[i] += arr[idx][i];
	
	func(idx + 1);
	
	selected.pop_back();
	for (int i = 0; i < 4; i++)
		pfsv[i] -= arr[idx][i];
		
	func(idx + 1);
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < 4; i++)
		scanf("%d", &mpfsv[i]);
	for (int i = 0; i < n; i++)
		for(int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);
	
	func(0);
	printf("%d\n", ans);
	if (ans != -1)
		for (int temp : minSelected)
			printf("%d ", temp + 1);
	
	return 0;
}

