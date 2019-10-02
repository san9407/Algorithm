//O(VEf)
//boj 11408

#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX_N = 401;
const int MAX_V = 2 * (MAX_N + 1);
const int S = MAX_V - 2;
const int E = MAX_V - 1;
const int INF = 1000000000;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int d[MAX_V][MAX_V];
vector<int> vt[MAX_V];
int pred[MAX_V];
int dist[MAX_V];
bool inQ[MAX_V];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = MAX_N; i <= MAX_N + M; i++)
	{
		c[i][E] = 1;
		vt[E].push_back(i);
		vt[i].push_back(E);
	}

	for (int i = 1; i <= N; i++)
	{
		int k;
		scanf("%d", &k);
		c[S][i] = 1;
		vt[S].push_back(i);
		vt[i].push_back(S);
		for (int j = 0; j < k; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			c[i][a+MAX_N] = 1;
			d[i][a+MAX_N] = b;
			d[a+MAX_N][i] = -b;
			vt[i].push_back(a+MAX_N);
			vt[a+MAX_N].push_back(i);
		}
	}
	int result = 0;
	int ans = 0;
	while (1)
	{
		queue<int> q;
		fill(pred, pred + MAX_V, -1);
		fill(dist, dist + MAX_V, INF);

		dist[S] = 0;
		q.push(S);
		inQ[S] = true;
		while (!q.empty())
		{
			int curr = q.front();
			q.pop();
			inQ[curr] = false;
			for (int i = 0; i < vt[curr].size(); i++)
			{
				int next = vt[curr][i];
				if (c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next])
				{
					dist[next] = dist[curr] + d[curr][next];
					pred[next] = curr;
					if (!inQ[next])
					{
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}

		if (pred[E] == -1)
			break;

		int flow = INF;
		for (int i = E; i != S; i = pred[i])
			flow = min(flow, c[pred[i]][i] - f[pred[i]][i]);

		for (int i = E; i != S; i = pred[i])
		{
			result += flow * d[pred[i]][i];
			f[pred[i]][i] += flow;
			f[i][pred[i]] -= flow;
		}
		ans += flow;
	}

	printf("%d\n%d\n", ans,result);
	return 0;
}
