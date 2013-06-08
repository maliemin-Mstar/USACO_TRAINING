/*
ID: maliemi2
PROG: money
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#define SIZE 1010
using namespace std;

ofstream fout ("money.out");
ifstream fin ("money.in");
long long dp[26][10001];

int main()
{
	int v, n, coin[26];
	fin >> v >> n;
	int i, j;
	for (i = 1; i <= v; ++i)
		fin >> coin[i];
	dp[1][0] = 1;
	for (i = 1; i <= n; ++i)
	{
		if (i % coin[1] == 0)
			dp[1][i] = 1;
		else
			dp[1][i] = 0;
	}
	for (i = 2; i <= v; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			int t = coin[i];
			dp[i][j] = dp[i - 1][j];
			while (j >= t)
			{
				dp[i][j] += dp[i - 1][j - t];
				t += coin[i];
			}
		}
	}
	fout << dp[v][n] << endl;
	return 0;
}