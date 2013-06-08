/*
ID: maliemi2
PROG: inflate
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

ofstream fout ("inflate.out");
ifstream fin ("inflate.in");

int main()
{
	int cost[10010], value[10010], dp[10010], m, n;

	int i, j;

	memset (dp, 0, sizeof(dp));

	fin >> m >> n;

	for (i = 0; i < n; ++i)
	{
	
		fin >> value[i] >> cost[i];
	
	}

	for (i = 0; i < n; ++i)
	{
	
		for (j = cost[i]; j <= m; ++j)
		{
		
			dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
		
		}
	
	}

	fout << dp[m] << endl;

	return 0;
}