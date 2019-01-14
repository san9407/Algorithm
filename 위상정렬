//위상정렬 기본코드
//백준 2252
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;
const int MAX = 1000000;
const int MOD = 100000007;

vector<vector<int> > adj;
int in[32001];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	adj.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		in[b]++;
	}
	vector<int> ans;
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (!in[i])
		{
			q.push(i);
			ans.push_back(i);
		}
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = 0; i < adj[curr].size(); i++)
		{
			int next = adj[curr][i];
			in[next]--;
			if (!in[next])
			{
				q.push(next);
				ans.push_back(next);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
