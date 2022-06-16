/*
�湮���� ���� ���� �߰��ϸ�, �ش� ������ ���� BFS�� ������ cnt�� ������Ų��.
���� ������ ���� �� ������ �����ϸ� ���� ������ cnt���� ���� �� �ִ�.
�밢�����ε� ����ȴٴ� ���� ��������. 
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

