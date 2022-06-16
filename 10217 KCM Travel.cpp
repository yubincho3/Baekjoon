/*
���ͽ�Ʈ�� �˰����� Ȱ���ϴ� ������.
priority_queue�� ����Ǵ� tuple�� ������� ����,
���� �̵��� �Ÿ�, ���� ����� ��, ���� ������ ��ȣ�̴�.
������ ���ͽ�Ʈ��ó�� �켱 �Ÿ��� �ּ�ȭ�ϵ�,
����� ���� m���Ͽ��� �Ѵٴ� ������ ����ؾ� �Ѵ�.
*/
#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
using namespace std;
using Tuple = tuple<int, int, int>; // dist, cost, vertex

vector<Tuple> arr[101];
int dist[101][10001];
int t, n, m, k;
int u, v, c, d;

int solve(void)
{
	if (k == 0)
		return INF;
	
	priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
	
	pq.push(make_tuple(0, 0, 1));
	dist[1][0] = 0;
	
	while (!pq.empty())
	{
		int nowDist, cost, now;
		tie(nowDist, cost, now) = pq.top();
		pq.pop();
		
		if (now == n)
			return nowDist;
		
		for (Tuple& temp : arr[now])
		{
			int nxtDist, nCost, nxt;
			tie(nxtDist, nCost, nxt) = temp;
			
			if (cost + nCost <= m && dist[nxt][cost + nCost] > nowDist + nxtDist)
			{
				dist[nxt][cost + nCost] = nowDist + nxtDist;
				pq.push(make_tuple(nowDist + nxtDist, cost + nCost, nxt));
			}
		}
	}
	
	return INF;
}

int main(void)
{
	for (scanf("%d", &t); t--;)
	{
		memset(dist, 0x7f, sizeof(dist));
		for (int i = 1; i <= n; i++)
			arr[i].clear();
		
		for (scanf("%d %d %d", &n, &m, &k); k--;)
		{
			scanf("%d %d %d %d", &u, &v, &c, &d);
			arr[u].push_back(make_tuple(d, c, v));
		}
		
		int ans = solve();
		printf(ans ^ INF ? "%d\n" : "Poor KCM\n", ans);
	}
	
	return 0;
}

