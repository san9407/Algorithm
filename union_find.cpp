//disjoint-set , union find 기본코드
//백준 1717
#include<cstdio>
using namespace std;

int arr[1000001];

int find(int x)
{
	if (arr[x] == x)
		return x;
	return arr[x] = find(arr[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	arr[x] = y;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int k, a, b;
		scanf("%d %d %d", &k, &a, &b);
		if (k == 0)
		{
			merge(a, b);
		}
		else if (k == 1)
		{
			if (find(a) == find(b))
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
