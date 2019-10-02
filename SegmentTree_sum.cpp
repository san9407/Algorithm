//O(NlogN)
//세그먼트트리 구간합 구하기
//boj 2042

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 1000000000;
const int MAX = 1000000;

long long arr[MAX];
long long tree[1 << 21];

void init(int node, int start, int end)
{
	if (start == end)
		tree[node] = arr[start];
	else
	{
		int mid = (start + end) >> 1;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(int node, int start, int end, int index,long long diff)
{
	if (index<start || index>end)
		return;
	tree[node] += diff;
	if (start != end)
	{
		int mid = (start + end) >> 1;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}

long long find(int node, int start, int end, int left, int right)
{
	if (right<start || left>end)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) >> 1;
	return find(node * 2, start, mid, left, right) + find(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	M += K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	init(1, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
		{
			long long c;
			cin >> c;
			b--;
			long long diff = c - arr[b];
			arr[b] = c;
			update(1, 0, N - 1, b, diff);
		}
		else if (a == 2)
		{
			int c;
			cin >> c;
			b--;
			c--;
			cout << find(1, 0, N - 1, b, c)<<'\n';
		}
	}
	
	return 0;
}
