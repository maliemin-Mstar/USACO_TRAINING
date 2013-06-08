/*
ID: maliemi2
PROG: nuggets
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
using namespace std;

ofstream fout ("nuggets.out");
ifstream fin ("nuggets.in");

int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int dp[256*256-256*2+1];
	int i, j;
	dp[0] = 0;
	for (i = 1; i < 256*256-256*2+1; ++i)
	{
		dp[i] = MYMIN;
	}
	int num[11], n;
	fin >> n;
	bool flag = 0;
	for (i = 0; i < n; ++i)
	{
		fin >> num[i];
		if (num[i] == 1)
			flag = 1;
	}
	if (flag)
	{
		fout << 0 << endl;
		return 0;
	}
	int k = num[0];
	for (i = 1; i < n; ++i)
	{
		k = gcd(k, num[i]);
	}
	if (k != 1)
	{
		fout << 0 << endl;
		return 0;
	}
	for (i = 0; i < n; ++i)
	{
		for (j = num[i]; j < 256*256-256*2+1; ++j)
		{
			dp[j] = max(dp[j], dp[j - num[i]] + num[i]);
		}
	}
	for (i = 256*256-256*2; i >= 1; --i)
	{
		if (dp[i] != i)
		{
			fout << i << endl;
			break;
		}
	}
	return 0;
}