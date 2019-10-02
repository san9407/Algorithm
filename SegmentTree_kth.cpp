//O(NlogN)
//boj 2243

#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 1000000;
const int MOD = 100000007;

int arr[MAX+1];
int tree[1 << 21];

void update(int node, int start, int end, int idx, int diff)
{
	if (idx<start || idx > end)
		return;
	tree[node] += diff;
	if (start != end)
	{
		int mid = (start + end) >> 1;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

int kth(int node, int start, int end, int val)
{
	if (start==end)
		return start;
	if (val <= tree[node*2])
	{
		kth(node * 2, start, (start + end) / 2, val);
	}
	else
	{
		kth(node * 2 + 1, (start + end) / 2 + 1, end, val - tree[node*2]);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1)
		{
			int b;
			scanf("%d", &b);
			int temp = kth(1, 1, MAX, b);
			printf("%d\n", temp);
			arr[temp]--;
			update(1, 1, MAX, temp, -1);
		}
		else
		{
			int b, c;
			scanf("%d %d", &b, &c);
			arr[b] += c;
			update(1, 1, MAX, b, c);
		}
	}
	
	return 0;
}
