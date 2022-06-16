/*
방문하지 않은 땅을 발견하면, 해당 지역에 대해 BFS를 돌리고 cnt를 증가시킨다.
지도 전역에 대해 위 과정을 수행하면 섬의 개수를 cnt에서 얻을 수 있다.
대각선으로도 연결된다는 것을 조심하자. 
*/
#include <bits/stdc++.h>
using namespace std;

int arr[51][51];
int visit[51][51];
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int w, h;

void BFS(int sx, int sy)
{
	queue<pair<int, int>> q;
	
	q.push(make_pair(sx, sy));
	visit[sy][sx] = 1;
	
	while (!q.empty())
	{
		auto now = q.front();
		q.pop();
		
		for (int i = 0; i < 8; i++)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			
			if (nx >= 0 && ny >= 0 && nx < w && ny < h)
			{
				if (!visit[ny][nx] && arr[ny][nx])
				{
					q.push(make_pair(nx, ny));
					visit[ny][nx] = 1;
				}
			}
		}
	}
}

int solve(void)
{
	int ret = 0;
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] && !visit[i][j])
			{
				BFS(j, i);
				ret++;
			}
		}
	}
	
	memset(visit, 0, sizeof(visit));
	
	return ret;
}

int main(void)
{
	while (true)
	{
		scanf("%d %d", &w, &h);
		
		if (!w && !h)
			break;
		
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &arr[i][j]);
		
		printf("%d\n", solve());
	}
	
	return 0;
}

