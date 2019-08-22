//백준 1786 찾기 문제
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 1000000;
const int MOD = 1000000007;

int fail[MAX + 1];
char A[MAX + 1];
char B[MAX + 1];

int main()
{
	//scanf("%[^\n]\n%[^\n]",A,B);
	//아마 A뒤에 '\0'을 안붙게되서 제출시 틀렸습니다 나옴.
	scanf("%[^\n]", A);
	getchar();
	scanf("%[^\n]", B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int i, j;
	for (i = 1, j = 0; i < lenB; i++)
	{
		while (j && B[i] != B[j])
			j = fail[j - 1];
		if (B[i] == B[j])
			fail[i] = ++j;
	}
	vector<int> ans;
	for (i = 0, j = 0; i < lenA; i++)
	{
		while (j&&A[i] != B[j])
			j = fail[j - 1];
		if (A[i] == B[j])
		{
			if (j == lenB - 1)
			{
				ans.push_back(i - lenB + 1);
				j = fail[j];
			}
			else
				j++;
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i] + 1);
	}
	puts("");
	return 0;
}
