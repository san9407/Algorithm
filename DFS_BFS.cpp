//dfs와 bfs의 시간복잡도는 O(N+M)
//boj 1260문제
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<int> v[1001];
bool check[1001];

void dfs(int node)
{
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		if (!check[next])
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (!check[next])
			{
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	int N, M,V;
	scanf("%d %d %d", &N, &M,&V);
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	puts("");
	memset(check, false, sizeof(check));
	bfs(V);
	puts("");
	return 0;
}
