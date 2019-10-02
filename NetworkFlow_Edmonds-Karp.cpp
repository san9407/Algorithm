//O(VE^2)
//boj 6086

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;
const long long LINF = 1000000000000000000;
const int MOD = 1000000007;
typedef long long ll;

int ctoi(char c)
{
	if (c <= 'Z')
		return c - 'A';
	else
		return c - 'a' + 26;
}

int c[52][52];
int f[52][52];
vector<int> adj[52];
int p[52];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char u, v;
		int w;
		scanf(" %c %c %d", &u, &v, &w);
		u = ctoi(u);
		v = ctoi(v);
		c[u][v] = c[v][u] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int total = 0;
	int S = ctoi('A'), E = ctoi('Z');
	while (1)
	{
		memset(p, -1, sizeof(p));
		queue<int> q;
		q.push(S);
		while (!q.empty() && p[E] == -1)
		{
			int curr = q.front();
			q.pop();
			for (int i = 0; i < adj[curr].size(); i++)
			{
				int next = adj[curr][i];
				if (c[curr][next] - f[curr][next] > 0 && p[next] == -1)
				{
					q.push(next);
					p[next] = curr;
					if (next == E)
						break;
				}
			}
		}
		if (p[E] == -1)
			break;
		int flow = INF;
		for (int i = E; i != S; i = p[i])
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		for (int i = E; i != S; i = p[i])
		{
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;
		}
		total += flow;
	}
	printf("%d\n", total);
	return 0;
}
