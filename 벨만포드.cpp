//벨만포드 기본코드
//백준 11657문제
//N-1번 돌리면 무조건 최단거리를 찾는데 1번더 돌림으로써 싸이클 있는지 
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;
const int MAX = 1000000;
const int MOD = 100000007;

vector<pair<int, int> > adj[501];
int dist[501];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		adj[a].push_back(make_pair(b, c));
	}
	fill(dist, dist + N, INF);
	dist[0] = 0;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < adj[j].size(); k++)
			{
				int next = adj[j][k].first;
				int cost = adj[j][k].second;
				if (dist[j] != INF&&dist[next] > dist[j] + cost)
				{
					dist[next] = dist[j] + cost;
					if (i == N - 1)
						flag = true;
				}
			}
		}
	}
	if (flag)
		puts("-1");
	else
	{
		for (int i = 1; i < N; i++)
		{
			printf("%d\n", dist[i] == INF ? -1 : dist[i]);
		}
	}
	return 0;
}
