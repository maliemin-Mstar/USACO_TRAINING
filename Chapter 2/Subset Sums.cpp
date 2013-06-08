/*
ID: maliemi2
PROG: subset
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

ofstream fout ("subset.out");
ifstream fin ("subset.in");

int main()
{
	int n;
	fin >> n;
	long long dp[40][790];
	int sum = (1 + n) * n / 2;
	if (sum & 1)
		fout << 0 << endl;
	else 
	{
		int halfsum = sum / 2;
		int i, j;
		dp[1][1] = 1;
		dp[1][0] = 1;
		for (i = 2; i <= halfsum; ++i)
			dp[1][i] = 0;
		for (i = 2; i <= n; ++i)
		{
			for (j = 0; j <= halfsum; ++j)
			{
				if (j >= i)
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
				else 
					dp[i][j] = dp[i - 1][j];
			}
		}
		fout << dp[n][halfsum] / 2 << endl;
	}
	return 0;
}