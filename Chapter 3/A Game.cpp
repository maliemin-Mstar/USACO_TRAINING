/*
ID: maliemi2
PROG: game1
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

ofstream fout ("game1.out");
ifstream fin ("game1.in");

int main()
{
	int dp[101][101], num[101], sum[101][101];
	memset (dp, 0, sizeof(dp));
	memset (sum, 0, sizeof(sum));
	int n, i, j;
	fin >> n;
	for (i = 1; i <= n; ++i)
	{
		fin >> num[i];
		dp[i][i] = num[i];
		sum[i][i] = num[i];
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = i + 1; j <= n; ++j)
		{
			sum[i][j] = sum[i][j - 1] + num[j];
		}
	}
	int k;
	for (k = 1; k < n; ++k)
	{
		for (i = 1; i + k <= n; ++i)
		{
			dp[i][i + k] = sum[i][i + k] - min(dp[i + 1][i + k], dp[i][i + k - 1]);
		}
	}
	fout << dp[1][n] << ' ' << sum[1][n] - dp[1][n] << endl;
	return 0;
}