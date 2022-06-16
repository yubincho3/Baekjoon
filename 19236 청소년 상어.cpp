/*
백트래킹+시뮬레이션 구현 문제다.
시뮬레이션 구현이 복잡해서 코드가 꼬일 수 있으니 조심해야 한다.
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> fish[17];
int arr[4][4][2];
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int ans = 0;

bool OutOfRange(int x, int y)
{
	return (x < 0 || y < 0 || x >= 4 || y >= 4);
}

void NewTurn(int sharkX, int sharkY, int sum)
{
	pair<int, int> saveFish[17];
	int saveArr[4][4][2];
	
	for (int i = 1; i < 17; i++)
	{
		saveFish[i].first = fish[i].first;
		saveFish[i].second = fish[i].second;
	}
	memcpy(saveArr, arr, sizeof(arr));
	
	int dir = arr[sharkY][sharkX][1];
	sum += arr[sharkY][sharkX][0];
	
	fish[arr[sharkY][sharkX][0]].first = -1;
	arr[sharkY][sharkX][0] = 0;
	
	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].first != -1)
		{
			int x = fish[i].first;
			int y = fish[i].second;
			int& d = arr[y][x][1];
			
			for (int j = 0; j < 8; j++)
			{
				int nx = x + dx[d];
				int ny = y + dy[d];
			
				if (!OutOfRange(nx, ny) && (nx != sharkX || ny != sharkY))
				{
					fish[arr[ny][nx][0]].first = x;
					fish[arr[ny][nx][0]].second = y;
					
					fish[i].first = nx;
					fish[i].second = ny;
					
					swap(arr[y][x][0], arr[ny][nx][0]);
					swap(arr[y][x][1], arr[ny][nx][1]);
					
					break;
				}
				else
					d = (d + 1) % 7;
			}
		}
	}
	
	bool flag = false;
	
	for (int i = 1; i <= 3; i++)
	{
		int nx = sharkX + dx[dir] * i;
		int ny = sharkY + dy[dir] * i;
		
		if (OutOfRange(nx, ny) == true)
			break;
		
		if (arr[ny][nx][0] > 0)
		{
			NewTurn(nx, ny, sum);
			flag = true;
		}
	}
	
	if (flag == false)
		ans = max(ans, sum);
	
	for (int i = 1; i < 17; i++)
	{
		fish[i].first = saveFish[i].first;
		fish[i].second = saveFish[i].second;
	}
	memcpy(arr, saveArr, sizeof(arr));
}

int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d %d", &arr[i][j][0], &arr[i][j][1]);
			fish[arr[i][j][0]].first = j;
			fish[arr[i][j][0]].second = i;
			arr[i][j][1]--;
		}
	}
	
	NewTurn(0, 0, 0);
	printf("%d\n", ans);
	
	return 0;
}

