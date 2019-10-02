//boj 10999
//바로바로 업데이트 해주는것이 아닌 필요한 순간에만 업데이트를 해준다.

#include <cstdio>

long long arr[1000001];
long long tree[2097153];
long long lazy[2097153];

long long init(int node, int start, int end)
{
	if (start == end)
	{
		return tree[node] = arr[start];
	}
	else
	{
		return tree[node]= init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2+1, end);
	}
}

void update_lazy(int node, int start, int end)
{
	if (lazy[node] != 0)
	{
		tree[node] += (end - start + 1)*lazy[node];
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int start, int end, int left, int right, long long diff)
{
	update_lazy(node, start, end);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] += (end - start + 1)*diff;
		if (start != end)
		{
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update_range(node * 2, start, (start + end) / 2, left, right, diff);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(int node, int start, int end, int left, int right)
{
	update_lazy(node, start, end);
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() 
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	M += K;
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	init(1, 1, N);
	for (int i = 0; i < M; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1)
		{
			int b, c;
			long long d;
			scanf("%d %d %lld", &b, &c, &d);
			update_range(1, 1, N, b, c, d);
		}
		else if (a == 2)
		{
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n",sum(1,1,N,b,c));
		}
	}
	return 0;
}
