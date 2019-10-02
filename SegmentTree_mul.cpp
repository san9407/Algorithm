//O(NlogN)
//세그먼트트리 구간의 곱 구하기
//boj 11505

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	init(arr, tree, node * 2, start, (start + end) / 2);
	init(arr,tree,node*2+1,(start+end)/2+1,end);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
	tree[node] %= 1000000007;
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
	if (index<start || index>end)
		return;
	if (start != end)
	{
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		tree[node] = tree[node * 2] * tree[node * 2 + 1] % 1000000007;
	}
	else
	{
		tree[node] = diff;
	}
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (right<start || left>end)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	return (sum(tree, node * 2, start, (start + end) / 2, left, right) * sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right) )% 1000000007;
}

int main()
{
	int N, M,K;
	scanf("%d %d %d", &N, &M,&K);
	int h = ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<long long> arr(N);
	vector<long long> tree(tree_size);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	init(arr,tree,1, 0, N - 1);
	for (int i = 0; i < M+K; i++)
	{
		int a;
		scanf("%d",&a);
		if (a == 1)
		{
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			//long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			update(tree, 1, 0, N - 1, b - 1, c);
		}
		else if (a == 2)
		{
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n",sum(tree,1,0,N-1, b - 1, c - 1));
		}
	}
	return 0;
}
