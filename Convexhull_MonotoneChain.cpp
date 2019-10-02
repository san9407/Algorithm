//O(NlogN)
//모노톤 체인으로 구현
//boj 1708
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAX 100000

struct Point
{
	int x, y;
	Point operator -(const Point& A)
	{
		return{ x - A.x,y - A.y };
	}
	bool operator <(const Point& A)
	{
		return x == A.x ? y < A.y : x < A.x;
	}
}p[MAX];

ll ccw(const Point& A, const Point& B)
{
	return 1LL*A.x*B.y - 1LL*B.x*A.y;
}
ll ccw(Point& A, Point& B, Point& C)
{
	return ccw(B - A, C - A);
}

Point uc[MAX], dc[MAX], convex[MAX];
int ut, dt, ct;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = { x,y };
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++)
	{
		while (ut >= 2 && ccw(uc[ut-2],uc[ut-1],p[i])>=0)
		{
			ut--;
		}
		uc[ut++] = p[i];
	}
	for (int i = N-1; i >=0; i--)
	{
		while (dt >= 2 && ccw(dc[dt-2],dc[dt-1],p[i]) >= 0)
		{
			dt--;
		}
		dc[dt++] = p[i];
	}
	for (int i = 0; i < ut-1; i++)
		convex[ct++] = uc[i];
	for (int i = 0; i < dt - 1; i++)
		convex[ct++] = dc[i];
	printf("%d\n", ct);
	return 0;
}
//모노톤체인으로 구현
