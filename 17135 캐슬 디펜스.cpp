/*
백트래킹+시뮬레이션 구현 문제다.
먼저 백트래킹으로 모든 조합을 얻고,
그 후 문제에서 요구하는 조건을 계산했다. 
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> deployed;
vector<int> deploy;
int arr[26][26];
int n, m, d; 

void SaveDeploy(int prevIdx)
{
	if (prevIdx == m - 1)
	{
		if (deploy.size() == 3)
			deployed.push_back(deploy);
		
		return;
	}
	
	for (int i = prevIdx + 1; i < m; i++)
	{
		deploy.push_back(i);
		
		if (deploy.size() == 3)
			SaveDeploy(m - 1);
		else
			SaveDeploy(i);
		
		deploy.pop_back();
	}
}

int solve(void)
{
	int original[16][16];
	memcpy(original, arr, sizeof(arr));
	
	int ret = 0;
	
	for (auto& deploy : deployed)
	{
		int eliminated = 0;
		
		while (true)
		{
			pair<int, int> tar[3] = { {d + m, 0}, {d + m, 0}, {d + m, 0} };
			
			bool flag = false;
			
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (arr[i][j] == 0)
						continue;
						
					for (int k = 0; k < 3; k++)
					{
						int dist = abs(deploy[k] - j) + abs(n - i);
						
						if (dist <= d)
						{
							int prevDist = abs(tar[k].first - deploy[k]) + abs(tar[k].second - n);
							
							if (dist == prevDist && tar[k].first > j || dist < prevDist)
							{
								tar[k].first = j;
								tar[k].second = i;
							}
						}
					} flag = true;
				}
			}
			
			if (flag == false)
			{
				memcpy(arr, original, sizeof(arr));
				ret = max(ret, eliminated);
				break;
			}
			
			for (int i = 0; i < 3; i++)
			{
				if (tar[i].first != d + m)
				{
					eliminated += arr[tar[i].second][tar[i].first];
					arr[tar[i].second][tar[i].first] = 0;
				}
			}
				
			for (int i = n - 1; i > 0; i--)
				for (int j = 0; j < m; j++)
					arr[i][j] = arr[i - 1][j];
					
			memset(arr[0], 0, sizeof(arr[0]));
		}
	}
	
	return ret;
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
			
	SaveDeploy(-1);
	printf("%d\n", solve());
	
	return 0;
}

