//O(V+E)
//타잔 알고리즘
//boj 2150

#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
using namespace std;
const int INF = 1000000000;

vector<vector<int> > adj;
int cnt,color;
int dfsn[10001];
int sn[10001];
bool finished[10001];
stack<int> s;
vector<vector<int>> scc;

int dfs(int curr)
{
	dfsn[curr] = ++cnt;
	s.push(curr);

	int result = dfsn[curr];
	for (int i = 0; i < adj[curr].size(); i++)
	{
		int next = adj[curr][i];
		if (dfsn[next] == 0)
			result = min(result, dfs(next));
		else if (!finished[next])
			result = min(result, dfsn[next]);
	}

	if (result == dfsn[curr])
	{
		vector<int> temp;
		while (1)
		{
			int t = s.top();
			s.pop();
			temp.push_back(t);
			finished[t] = true;
			sn[t] = color;
			if (t == curr)
				break;
		}
		sort(temp.begin(), temp.end());
		scc.push_back(temp);
		color++;
	}
	return result;
}

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	adj.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		adj[A].push_back(B);
	}
	for (int i = 1; i <= V; i++)
	{
		if (dfsn[i] == 0)
			dfs(i);
	}
	sort(scc.begin(), scc.end());
	printf("%d\n", color);
	for (int i = 0; i < scc.size(); i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
		{
			printf("%d ", scc[i][j]);
		}
		puts("-1");
	}
	return 0;
}
