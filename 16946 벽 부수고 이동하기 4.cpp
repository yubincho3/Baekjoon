/*
평범한 BFS 문제에서 약간의 변경을 줘야하는 문제다.
빈 공간에 대해 BFS를 돌려서 공간들에 번호를 매기고,
vector에 그 공간 순서대로 넓이를 저장했다.
그 후 문제에서 요구하는 조건을 출력한다. 
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> area;
int arr[1001][1001];
int visit[1001][1001];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, m;

void BFS(int x, int y)
{
	const int areaNum = area.size() + 1;
	int areaCnt = 1;
	
	queue<pair<int, int>> q;
	
	visit[y][x] = areaNum;
	q.push({x, y});
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			
			if (!visit[ny][nx] && !arr[ny][nx])
			{
				visit[ny][nx] = areaNum;
				q.push({nx, ny});
				areaCnt++;
			}
		}
	}
	
	area.push_back(areaCnt);
}

int GetSurroundSum(int x, int y)
{
	int ret = 1;
	set<int> s;
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= m || ny >= n || arr[ny][nx])
			continue;
			
		s.insert(visit[ny][nx] - 1);
	}
	
	for (int temp : s)
		ret += area[temp];
	
	return ret % 10;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!arr[i][j] && !visit[i][j])
				BFS(j, i);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d", arr[i][j] ? GetSurroundSum(j, i) : 0);
		printf("\n");
	}

	return 0;
}

