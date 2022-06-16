/*
���ͽ�Ʈ�� �˰����� Ȱ���ϴ� ������.
���� ��� �˼��� Ż���ϴ� ��츦 ����ϱ� ����,
�˼��� �����δ� �������� ���� �ۿ��� ����̵� �����δٰ� �����Ѵ�.
�˼� 2��� ����̿� ���� ���ͽ�Ʈ�� ������(dist�� ������ ���� �����̴�),
3���� ���ͽ�Ʈ�� ����� �����Ѵ�.
�� �� 3�� ��� ���� ������ ������ ���ؼ�,
3���� ���ͽ�Ʈ�� ���� ��� ���� ������ �ּڰ��� ���ϸ� �ȴ�.
���⼭, ���� �ִ� �ε����� ���� ��� ���� �� ��� ���� �� ������ ��޵Ǿ� �ߺ��ǹǷ�,
2�� ���༭ �ߺ��� �����ؾ� �Ѵ�. 
*/
#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
using namespace std;
using Tuple = tuple<int, int, int>;

char arr[102][102];
int dist[102][102];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int t, h, w;

void Dijikstra(int x, int y)
{
	memset(dist, 0x7f, sizeof(dist));
	
	priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
	
	pq.push(make_tuple(0, x, y));
	dist[y][x] = 0;
	
	while (!pq.empty())
	{
		int d, x, y;
		tie(d, x, y) = pq.top();
		pq.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx > w + 1 || ny > h + 1)
				continue;
			
			int nd = dist[y][x] + (arr[ny][nx] == '#');
			
			if (dist[ny][nx] > nd && arr[ny][nx] != '*')
			{
				pq.push(make_tuple(nd, nx, ny));
				dist[ny][nx] = nd;
			}
		}
	}
}

int solve(vector<pair<int, int>> pos)
{
	int save[3][102][102] = {};
	
	pos.push_back({0, 0});
	for (int i = 0; i < 3; i++)
	{
		Dijikstra(pos[i].first, pos[i].second);
		memcpy(save[i], dist, sizeof(dist));
	}
	
	int ret = INF;
	
	for (int i = 0; i <= h + 1; i++)
	{
		for (int j = 0; j <= w + 1; j++)
		{
			if (arr[i][j] != '*')
			{
				bool flag = true;
				int sum = -2 * (arr[i][j] == '#');
				
				for (int k = 0; k < 3; k++)
				{
					if (save[k][i][j] == INF)
					{
						flag = false;
						break;
					}
					sum += save[k][i][j];
				}
				
				flag && (ret = min(ret, sum));
			}
		}
	}
	
	memset(arr, 0, sizeof(arr));
	
	return ret;
}

int main(void)
{
	for (scanf("%d", &t); t--;)
	{
		vector<pair<int, int>> v;
		
		scanf("%d %d", &h, &w);
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				scanf(" %c", &arr[i][j]);
				
				if (arr[i][j] == '$')
					v.push_back({j, i});
			}
		}
		
		printf("%d\n", solve(v));
	}
	
	return 0;
}

