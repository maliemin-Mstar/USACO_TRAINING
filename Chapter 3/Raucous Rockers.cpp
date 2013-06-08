/*
ID: maliemi2
PROG: rockers
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#define SIZE 22
#define MYMAX 1073741823
using namespace std;

ofstream fout ("rockers.out");
ifstream fin ("rockers.in");

int main()
{
	int N, T, M, len[21];
	fin >> N >> T >> M;
	int dp[21][21][21];
	memset (dp, 0, sizeof(dp));
	int i, j, k;
	for (i = 1; i <= N; ++i)
	{
		fin >> len[i];
	}
	/*for (i = 1; i <= N; ++i)
	{
		for (j = len[i]; j <= T; ++j)
		{
			dp[1][i][j] = max(dp[1][i - 1][j], dp[1][i - 1][j - len[i]] + 1);
		}
	}*/
	for (i = 1; i <= M; ++i)
	{
		for (j = 1; j <= N; ++j)
		{
			for (k = 0; k <= T; ++k)
			{
				dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][j][T]);
				if (k >= len[j])
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - len[j]] + 1);
			}
		}
	}
	fout << dp[M][N][T] << endl;
	return 0;
}