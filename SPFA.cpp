//SPFA 기본코드
//백준 11657 문제
//시간복잡도 O(VE)이지만 평균 O(E)에 해결한다함
//근데 막상 돌려보면 벨만포드보다 느리게 나옴 ㅡㅡ
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
bool check[501];
int cycle[501];

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
	queue<int> q;
	q.push(0);
	check[0] = true;
	cycle[0]++;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		check[here] = false;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i].first;
			int cost = adj[here][i].second;
			if (dist[next] > dist[here] + cost)
			{
				dist[next] = dist[here] + cost;
				if (!check[next])
				{
					cycle[next]++;
					check[next] = true;
					q.push(next);
					if (cycle[next] >= N)
					{
						puts("-1");
						return 0;
					}
				}
			}
		}
	}
	for (int i = 1; i < N; i++)
		printf("%d\n", dist[i] == INF ? -1 : dist[i]);
	return 0;
}

//SPFA 오랜만에 복습
