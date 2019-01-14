//lca 기본코드
//백준 11438문제
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 100000;
const int MOD = 100000007;

vector<int> adj[MAX];
bool visit[MAX];
int dep[MAX];
int par[20][MAX];

int lca(int u, int v)
{
	if (dep[u] > dep[v])
		swap(u, v);
	for (int i = 19; i >= 0; i--)
	{
		int diff = dep[v] - dep[u];
		if (diff >= (1 << i))
			v = par[i][v];
	}
	if (u == v)
		return u;
	for (int i = 19; i >= 0; i--)
	{
		if (par[i][u] != par[i][v])
		{
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

void dfs(int curr)
{
	visit[curr] = true;
	for (int i = 0; i < adj[curr].size(); i++)
	{
		int next = adj[curr][i];
		if (!visit[next])
		{
			par[0][next] = curr;
			dep[next] = dep[curr] + 1;
			dfs(next);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j < N; j++)
		{
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		printf("%d\n", lca(a, b)+1);
	}
	return 0;
}
