//O(NlogN)
//boj 2357

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	init(arr, tree, node * 2, start, mid);
	init(arr, tree, node * 2 + 1, mid + 1, end);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int init2(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	init2(arr, tree, node * 2, start, mid);
	init2(arr, tree, node * 2 + 1, mid + 1, end);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int find(vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return -1;
	if (left <= start && end <= right)
		return tree[node];
	int m1=find(tree, node * 2, start, (start + end) / 2, left, right);
	int m2=find(tree, node * 2 + 1, (start + end) / 2 + 1, end,left,right);
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	else
		return min(m1, m2);
}
int find2(vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return -1;
	if (left <= start && end <= right)
		return tree[node];
	int m1 = find2(tree, node * 2, start, (start + end) / 2, left, right);
	int m2 = find2(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	else
		return max(m1, m2);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int h = ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<int> arr(N);
	vector<int> tree_min(tree_size);
	vector<int> tree_max(tree_size);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	init(arr, tree_min, 1, 0, N - 1);
	init2(arr, tree_max, 1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n",find(tree_min, 1, 0, N - 1, a - 1, b - 1),find2(tree_max,1,0,N-1,a-1,b-1));
	}
	
	return 0;
}
