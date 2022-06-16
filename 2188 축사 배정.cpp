/*
��� ���� ������ ���� DFS�� ������. 
���� Ž���ϴ� ��� now�� ����ְų�,
�ٸ� �������� �� �� �ִٸ�.
�� x�� ��翡 �� �� �ִ�.
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

