/*
�����佺�׳׽��� ü�� ����Ͽ� ������ ������ ����ϸ� �ȴ�. 
*/
#include <bits/stdc++.h>
using namespace std;

bool arr[1001];
int n, k;

int main(void)
{
	scanf("%d %d", &n, &k);
	
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == false)
		{
			for (int j = 1; i * j <= n; j++)
			{
				if (arr[i * j] == false)
				{
					if (--k == 0)
					{
						printf("%d\n", i * j);
						return 0;
					}
					
					arr[i * j] = true;	
				}
			}
		}
	}
	
	return 0;
}

