/*
ID: maliemi2
PROG: range
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

ofstream fout ("range.out");
ifstream fin ("range.in");

int main()
{
	char mp[251][251];
	int dp[251][251];
	int n;
	fin >> n;
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			fin >> mp[i][j];
		}
	}
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n; i++)
	{
		if (mp[n][i] == '1')
			dp[n][i] = 1;
		else
			dp[n][i] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		if (mp[i][n] == '1')
			dp[i][n] = 1;
		else
			dp[i][n] = 0;
	}
	int max_s = 0;
	for (i = n - 1; i > 0; --i)
	{
		for (j = n - 1; j > 0; --j)
		{
			if (mp[i][j] == '1')
				dp[i][j] = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1]) + 1;
			if (dp[i][j] > max_s)
				max_s = dp[i][j];
		}
	}
	int cnt[251];
	memset (cnt, 0, sizeof(cnt));
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (dp[i][j] >= 2)
			{
				for (int k = 2; k <= dp[i][j]; ++k)
				{
					cnt[k]++;
				}
			}
		}
	}
	for (i = 2; i <= max_s; ++i)
	{
		fout << i << ' ' << cnt[i] << endl;
	}
	return 0;
}