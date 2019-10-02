//O(V+E)
//boj 11280
//not으로 바꿔주는 부분을 주의하자.

#include <cstdio>
#include <queue>
#include <vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;

vector<int> vt[20000];
int num[20000];
int low[20000];
bool check[20000];
int group[20000];
stack<int> s;
int cnt = 0;
int color = 0;
int dfs(int x)
{
	check[x] = true;
	s.push(x);
	num[x] = ++cnt;
	low[x] = cnt;
	for (int i = 0; i < vt[x].size(); i++)
	{
		int y = vt[x][i];
		if (num[y] == 0)
		{
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		else if (check[y] == true)
		{
			low[x] = min(low[x], num[y]);
		}
	}
	if (low[x] == num[x])
	{
		while (!s.empty())
		{
			int y = s.top();
			s.pop();
			group[y] = color;
			check[y] = false;
			if (x == y)
				break;
		}
		color++;
	}
}

int oppo(int n)
{
	return n % 2 ? n - 1 : n + 1;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int A,B;
		scanf("%d %d", &A, &B);
		A = (A < 0 ? -(A + 1) * 2 : A * 2 - 1);
		B = (B < 0 ? -(B + 1) * 2 : B * 2 - 1);

		vt[oppo(A)].push_back(B);
		vt[oppo(B)].push_back(A);
	}

	for (int i = 0; i < N * 2; i++)
	{
		if (num[i] == 0)
			dfs(i);
	}
	
	for (int i = 0; i < N; i++)
	{
		if (group[i * 2] == group[i * 2 + 1])
		{
			puts("0");
			return 0;
		}
	}
	puts("1");
	return 0;
}
