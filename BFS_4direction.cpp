//bfs 4방향 탐색 O(N)
//boj 7576 토마토 문제

#include<cstdio>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int N, M;

int arr[1001][1001];
int map[1001][1001];
bool check[1001][1001];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int cnt = 0;

queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int rx = q.front().first;
		int ry = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = rx + dx[i];
			int ty = ry + dy[i];
			if (tx<1 || ty<1 || tx>M || ty>N || check[tx][ty] == true || arr[tx][ty]==-1)
			{
				continue;
			}
			else
			{
				check[tx][ty] = true;
				map[tx][ty] = map[rx][ry] + 1;
				q.push({ tx,ty });
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N,&M);
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int k;
			scanf("%d", &k);
			arr[i][j] = k;
			if (k == -1)
			{
				map[i][j] = -1;
			}
		}
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (check[i][j] == false && arr[i][j]==1)
			{
				q.push({ i,j });
				check[i][j] = true;
				map[i][j] = 1;
			}
		}
	}
	bfs();
	int max = 0;
	bool flag = false;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] > max)
			{
				max = map[i][j];
			}
			if (map[i][j] == 0)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	if (max == 1)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", max-1);
	}
	return 0;
}
