/*
아주 평범한 BFS 문제다... 
*/
#include <bits/stdc++.h>
using namespace std;

bool arr[1001][1001];
bool visit[1001];
int n, m, u, v;

void BFS(int start)
{
	queue<int> q;
	
	q.push(start);
	visit[start] = true;
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		for (int i = 1; i <= n; i++)
		{
			if (arr[now][i] && !visit[i])
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}
}

int solve(void)
{
	int ret = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i] && arr[i])
		{
			BFS(i);
			ret++;
		}
	}
	
	return ret;
}

int main(void)
{
	for (scanf("%d %d", &n, &m); m--;)
	{
		scanf("%d %d", &u, &v);
		arr[u][v] = true;
		arr[v][u] = true;
	}
	
	printf("%d\n", solve());
	
	return 0;
}

