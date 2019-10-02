//O(ElogV)
//프림 알고리즘으로 최소 스패닝 트리를 짜는법
//밀집 그래프 일수록 프림이 유리하고
//희소 그래프 일수록 크루스칼이 유리하다.
//

#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

vector<pair<int,int>> vt[10001];
bool visit[10001];

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		vt[A].push_back({ B,C });
		vt[B].push_back({ A,C });
	}
	int ans = 0;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	visit[1] = true;
	for (int i = 0; i < vt[1].size(); i++)
	{
		int start = vt[1][i].first;
		int startCost = vt[1][i].second;

		pq.push({ startCost,start });
	}

	while (!pq.empty())
	{
		int node = pq.top().second;
		int nodeCost = pq.top().first;
		pq.pop();
		if (visit[node])
			continue;
		visit[node] = true;
		ans += nodeCost;

		for (int i = 0; i < vt[node].size(); i++)
		{
			int next = vt[node][i].first;
			int nextCost = vt[node][i].second;
			pq.push({ nextCost,next });
		}
	}
	printf("%d\n", ans);
	return 0;
}
