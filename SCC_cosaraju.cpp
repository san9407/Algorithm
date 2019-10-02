//O(V+E)
//코사라주 알고리즘
//boj 2150

#include <cstdio>
#include<cstring>
#include<cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> a[10001];
vector<int> ar[10001];
int component[10001];
bool check[10001];
vector<int> order;

void dfs(int x)
{
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++)
	{
		int next = a[x][i];
		if (!check[next])
			dfs(next);
	}
	order.push_back(x);
}

void dfs_rev(int x, int cn)
{
	check[x] = true;
	component[x] = cn;
	for (int i = 0; i < ar[x].size(); i++)
	{
		int next = ar[x][i];
		if (!check[next])
			dfs_rev(next,cn);
	}
}
int main() 
{
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		a[A].push_back(B);
		ar[B].push_back(A);
	}
	for (int i = 1; i <= V; i++)
	{
		if (check[i] == false)
		{
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
	memset(check, false, sizeof(check));
	int cnt = 0;
	for (int i = 0; i < V; i++)
	{
		if (component[order[i]] == 0)
		{
			cnt++;
			dfs_rev(order[i], cnt);
		}
	}
	printf("%d\n", cnt);
	vector<vector<int>> ans(cnt);
	for (int i = 1; i <= V; i++)
	{
		ans[component[i] - 1].push_back(i);
	}
	for (int i = 0; i < cnt; i++)
	{
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}
