/*
모든 소의 정보에 대해 DFS를 돌린다. 
현재 탐색하는 축사 now가 비어있거나,
다른 공간에도 들어갈 수 있다면.
소 x는 축사에 들어갈 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
 
vector<int> v[201];
int arr[201];
int visit[201];
int n, m, s, si;

bool DFS(int now)
{
	for (int i = 0; i < v[now].size(); i++)
	{
		int nxt = v[now][i];
		
		if (visit[nxt] == false)
		{
			visit[nxt] = true;
			
			if (arr[nxt] == 0 || DFS(arr[nxt]))
			{
				arr[nxt] = now;
				return true;
			}
		}
	}
    
	return false;
}

int solve(void)
{
	int ret = 0;
	
	for (int i = 1; i <= n; i++)
	{
		ret += DFS(i);
		memset(visit, 0 , sizeof(visit));
	}
	
	return ret;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s);
		for (int j = 1; j <= s; j++)
		{
			scanf("%d", &si);
			v[i].push_back(si);
		}
	}
	
	printf("%d\n", solve());
	
	return 0;
}

