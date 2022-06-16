/*
다익스트라 알고리즘을 활용하는 문제다.
priority_queue에 저장되는 tuple은 순서대로 각각,
현재 이동한 거리, 현재 사용한 돈, 현재 정점의 번호이다.
기존의 다익스트라처럼 우선 거리를 최소화하되,
사용한 돈이 m이하여야 한다는 조건을 고려해야 한다.
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

