/*
ID: maliemi2
PROG: stamps
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

ofstream fout ("stamps.out");
ifstream fin ("stamps.in");
int dp[2500100];//前i种邮票面值和为j需要的最少张数

int main()
{
	int k, n, value[55], i, j, my_max = -1, l;
	fin >> k >> n;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < n; ++i)
	{
		fin >> value[i];
		if (value[i] > my_max)
			my_max = value[i];
	}
	int sum = my_max * k;
	for (j = 0; j <= sum; ++j)
	{
		if (j % value[0] == 0)
			dp[j] = j / value[0];
		else 
			dp[j] = 300;
	}
	for (i = 1; i < n; i++)
	{
		for (j = value[i]; j <= sum; ++j)
		{
			dp[j] = min(dp[j], dp[j - value[i]] + 1);
		}
	}
	for (i = 1; i <= sum; ++i)
	{
		if (dp[i] > k)
			break;
	}
	fout << i - 1 << endl;
	return 0;
}