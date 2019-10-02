//O(NlogN)인건 모노톤체인 방법과 똑같지만
//구현방법이 모노톤체인이 더 쉽다.
//이건 각정렬을 해야한다.
//boj 1708

#include <cstdio>
#include <algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
const int INF = 1000000000;
const int MAX = 100000;

struct Point
{
	int x, y;
	int p, q;
	Point() :Point(0, 0, 1, 0) {}
	Point(int x1, int y1)
		:x(x1), y(y1), p(1), q(0) {}
	Point(int x1, int y1, int p1, int q1)
		:x(x1), y(y1), p(p1), q(q1) {}
	bool operator <(const Point& O)
	{
		if (1LL * q*O.p != 1LL * p*O.q)
			return 1LL * q*O.p < 1LL * p*O.q;
		if (y != O.y)
			return y < O.y;
		return x < O.x;
	}
};

long long ccw(const Point& A, const Point& B, const Point& C)
{
	return 1LL * (B.x - A.x)*(C.y - A.y) - 1LL * (B.y - A.y)*(C.x - A.x);
}

int main()
{
	int N;
	scanf("%d", &N);
	Point p[MAX];
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = Point(x, y);
	}
	sort(p, p + N);
	for (int i = 1; i < N; i++)
	{
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p + 1, p + N);

	stack<int> s;
	s.push(0);
	s.push(1);
	int next = 2;
	while (next < N)
	{
		while (s.size() >= 2)
		{
			int second = s.top();
			s.pop();
			int first = s.top();
			if (ccw(p[first], p[second], p[next]) > 0)
			{
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}
	printf("%d\n", s.size());
	return 0;
}
//http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220857597424&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=postList
//마리오님 블로그
