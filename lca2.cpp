//lca를 이용하여 거리 구하기
//백준 3176 문제
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

vector<pair<int, int> > adj[MAX+1];
int par[20][MAX+1];
bool visit[MAX + 1];
int dep[MAX + 1];
long long maxx[20][MAX + 1];
long long minn[20][MAX + 1];

pair<long long,long long> lca(int u, int v)
{
	pair<long long,long long> ret = { -INF * 100LL,INF * 100LL };
	if (dep[u] > dep[v])
		swap(u, v);
	for (int i = 19; i >= 0; i--)
	{
		int diff = dep[v] - dep[u];
		if (diff >= (1 << i))
		{
			ret.first = max(ret.first, maxx[i][v]);
			ret.second = min(ret.second, minn[i][v]);
			v = par[i][v];
		}
	}
	if (u == v)
		return ret;
	for (int i = 19; i >= 0; i--)
	{
		if (par[i][u] != par[i][v])
		{
			ret.first = max({ ret.first,maxx[i][u],maxx[i][v] });
			ret.second = min({ ret.second,minn[i][u],minn[i][v] });
			u = par[i][u];
			v = par[i][v];
		}
	}
	ret.first = max({ ret.first,maxx[0][u],maxx[0][v] });
	ret.second = min({ ret.second,minn[0][u],minn[0][v] });
	return ret;
}

void dfs(int x)
{
	visit[x] = true;
	for (int i = 0; i < adj[x].size(); i++)
	{
		int next = adj[x][i].first;
		int cost = adj[x][i].second;
		if (!visit[next])
		{
			dep[next] = dep[x] + 1;
			par[0][next] = x;
			maxx[0][next] = cost;
			minn[0][next] = cost;
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
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dfs(1);
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			par[i][j] = par[i - 1][par[i - 1][j]];
			maxx[i][j] = max(maxx[i-1][j],maxx[i - 1][par[i - 1][j]]);
			minn[i][j] = min(minn[i-1][j],minn[i - 1][par[i - 1][j]]);
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		auto ans = lca(a, b);
		printf("%lld %lld\n", ans.second, ans.first);
	}
	return 0;
}
