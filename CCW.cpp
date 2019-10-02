//ccw와 교차하는지 
//boj 2162

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define abs(N) N>=0 ? N:-N
#define min(a,b) a>b ? b:a
#define max(a,b) a>b ? a:b

struct Point
{
	int x;
	int y;
	Point operator -(const Point& A)
	{
		return{ x - A.x,y - A.y };
	}
	bool operator <(const Point& A)
	{
		return x == A.x ? y < A.y : x < A.x;
	}
};

int ccw(const Point& A, const Point& B)
{
	return A.x*B.y - B.x*A.y;
}

ll ccw(Point& A, Point& B, Point& C)
{
	return ccw(B - A, C - A);
}

bool is_cross(Point A, Point B, Point C, Point D)
{
	ll ab = ccw(A, B, C)*ccw(A, B, D);
	ll cd = ccw(C, D, A)*ccw(C, D, B);
	if (ab == 0 && cd == 0)
	{
		bool flag = false;
		if (B < A)
			swap(A, B);
		if (D < C)
			swap(C, D);
		if (B<C||D<A)
			return false;
		return true;
	}
	return ab <= 0 && cd <= 0;
}

int par[3000];
int sz[3000];
Point p1[3000];
Point p2[3000];
bool check[3000];

int find(int x)
{
	if (x == par[x])
		return x;
	return par[x] = find(par[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	par[x] = y;
	sz[y] += sz[x];
	sz[x] = 1;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		par[i] = i;
		sz[i] = 1;
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		p1[i] = { x1,y1 };
		p2[i] = { x2,y2 };
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			if (is_cross(p1[i], p2[i], p1[j], p2[j]))
			{
				merge(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		find(i);
	}
	
	int cnt = 0;
	int maxx = 0;
	for (int i = 0; i < N; i++)
	{
		if (!check[par[i]])
		{
			check[par[i]] = true;
			cnt++;
			maxx = max(maxx, sz[par[i]]);
		}
	}
	printf("%d\n%d\n", cnt, maxx);
	return 0;
}
