//O(N^3)
//인하대IUPC 연예인은 힘들어문제
//정점에 여러 간선이 갈수있기에 플로이드 워셜을 쓸땐 min값으로 넣어줘야한다.
//boj 17270

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

int arr[100][100];

int main()
{
	int V, M;
	scanf("%d %d", &V, &M);
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (i == j)
				continue;
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		arr[a][b] = min(arr[a][b],c);
		arr[b][a] = min(arr[b][a],c);
	}
	int J, S;
	scanf("%d %d", &J, &S);
	J--;
	S--;
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
	int minn = INF;
	int minn2 = INF;
	int ans = -1;
	for (int i = 0; i < V; i++)
	{
		if (i == J || i == S)
			continue;
		if (minn > arr[J][i] + arr[S][i])
		{
			minn = arr[J][i] + arr[S][i];
		}
	}
	for (int i = V - 1; i >= 0; i--)
	{
		if (i == J || i == S)
			continue;
		if (arr[J][i]+arr[S][i]==minn&&arr[J][i] <= arr[S][i])
		{
			if (minn2 >= arr[J][i])
			{
				minn2 = arr[J][i];
				ans = i + 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
