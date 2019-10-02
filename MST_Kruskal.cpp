//O(ElogE)
//최소 스패닝 트리 크루스칼로 짜는방법
//희소 테이블(sparse table)일땐 크루스칼로 짜는게 유리하고
//밀집 테이블(dense table)일땐 프림이 유리하다.
//boj 1197

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int par[10001];

typedef struct kruskal
{
	int from;
	int to;
	int val;
}KS;

bool cmp(KS& a, KS& b)
{
	return a.val < b.val;
}

int find(int x)
{
	if (x == par[x])
		return x;
	else
		return par[x] = find(par[x]);
}

bool merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y)
		return false;
	par[x] = y;
	return true;
}

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	KS ks[100000];
	for (int i = 1; i <= V; i++)
	{
		par[i] = i;
	}
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ks[i].from = a-1;
		ks[i].to = b-1;
		ks[i].val = c;
	}

	sort(ks, ks + E, cmp);

	int ans = 0;
	int cnt = 0;
	for(int i = 0; i < E; i++)
	{
		if (merge(ks[i].from, ks[i].to))
		{
			ans += ks[i].val;
			cnt++;
			if (cnt == V - 1)
				break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
