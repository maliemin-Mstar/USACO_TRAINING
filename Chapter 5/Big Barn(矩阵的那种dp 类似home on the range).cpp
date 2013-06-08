/*---------
---------*/
/*
ID: maliemi2
PROG: bigbrn
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
#define MYMIN -1073741823
#define square(x) ((x) * (x))
using namespace std;

ofstream fout ("bigbrn.out");
ifstream fin ("bigbrn.in");
int n, dp[1001][1001];
bool mp[1001][1001];

int main()
{
	int t;
	memset (mp, 0, sizeof(mp));
	int i, j;
	fin >> n >> t;
	for (i = 0; i < t; ++i)
	{
		int x, y;
		fin >> x >> y;
		mp[x][y] = 1;
	}
	int max_l = 0;
	for (i = 1; i <= n; ++i)
	{
		if (mp[i][n])
			dp[i][n] = 0;
		else
			dp[i][n] = 1;
		if (dp[i][n] > max_l)
			max_l = dp[i][n];
		if (mp[n][i])
			dp[n][i] = 0;
		else
			dp[n][i] = 1;
		if (dp[n][i] > max_l)
			max_l = dp[n][i];
	}
	for (i = n - 1; i > 0; --i)
	{
		for (j = n - 1; j > 0; --j)
		{
			if (mp[i][j])
				dp[i][j] = 0;
			else
				dp[i][j] = min(min(dp[i + 1][j], dp[i + 1][j + 1]), dp[i][j + 1]) + 1;
			if (dp[i][j] > max_l)
				max_l = dp[i][j];
		}
	}
	fout << max_l << endl;
	return 0;
}