//O(VE)
//boj 2188

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
#include<functional>
#include<iomanip>
#include<list>
using namespace std;
const int INF = 1000000000;

vector<int> adj[201];
bool visit[201];
int B[201];

bool dfs(int x)
{
	visit[x] = true;
	for (int i = 0; i < adj[x].size(); i++)
	{
		int next = adj[x][i];
		if (B[next] == -1 || !visit[B[next]] && dfs(B[next]))
		{
			B[next] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	int N,M;
	scanf("%d %d", &N,&M);
	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			int u;
			scanf("%d", &u);
			adj[i].push_back(u);
		}
	}
	int ans = 0;
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= N; i++)
	{
		memset(visit, false, sizeof(visit));
		if (dfs(i))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
