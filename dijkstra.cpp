//다익스트라 기본코드
//백준 1753
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;
const int MAX = 20000;
const int MOD = 100000007;

vector<pair<int, int> > adj[MAX];
int dist[MAX];

int main()
{
	int V, E,K;
	scanf("%d %d %d", &V, &E, &K);
	K--;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--;
		v--;
		adj[u].push_back({ v,w });
	}
	fill(dist, dist + V, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ 0,K });
	dist[K] = 0;
	while (!pq.empty())
	{
		int curr = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < adj[curr].size(); i++)
		{
			int next = adj[curr][i].first;
			int nextCost = adj[curr][i].second;
			if (dist[next] > dist[curr] + nextCost)
			{
				dist[next] = dist[curr] + nextCost;
				pq.push({ dist[next],next });
			}
		}
	}
	for (int i = 0; i < V; i++)
	{
		if (dist[i] == INF)
			puts("INF");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}
