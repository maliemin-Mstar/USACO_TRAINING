/*
ID: maliemi2
PROG: kimbits
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

ofstream fout ("kimbits.out");
ifstream fin ("kimbits.in");
unsigned int dp[32][32], I;
int len;
bool lef = 0, righ = 0;

void solve(int n, int l)
{
	if (l == 0)
	{
		righ = 1;
		len = n;
		return;
	}
	if (n == l)
	{
		lef = 1;
		len = n;
		return;
	}
	if (I > dp[n - 1][l])
	{
		fout << 1;
		I -= dp[n - 1][l];
		solve(n - 1, l - 1);
	}
	else
	{
		fout << 0;
		solve(n - 1, l);
	}
}

void binary(unsigned int a, int n)
{
	unsigned int t = 1 << (n - 1);
	for (; t != 0; t >>= 1)
	{
		if ((a & t) != 0)
		{
			fout << 1;
		}
		else 
		{
			fout << 0;
		}
	}
	fout << endl;
}

int main()
{
	int N, L, i, j, t = 2;
	fin >> N >> L >> I;
	for (i = 1; i <= N; ++i)
	{
		dp[i][1] = i + 1;
		dp[i][i] = t;
		t *= 2;
	}
	for (i = 2; i <= N; ++i)
	{
		for (j = 2; j <= L; ++j)
		{
			if (i - 1 >= j)
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	solve(N, L);
	if (lef)
	{
		I--;
		binary(I, len);
	}
	else if (righ)
	{
		for (i = 0; i < len; ++i)
			fout << 0;
		fout << endl;
	}
	return 0;
}