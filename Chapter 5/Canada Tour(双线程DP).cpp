/*-----------------
-----------------*/
/*
ID: maliemi2
PROG: tour
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
#include <stack>
#define SIZE 1001
#define NHASH 99991
#define MYMAX 1073741823
#define MYMIN -1073741823
typedef unsigned short int USI;
using namespace std;

ofstream fout ("tour.out");
ifstream fin ("tour.in");
bool M[101][101];
int dp[101][101];

int main()
{
	memset(M, 0, sizeof(M));
	memset(dp, 0, sizeof(dp));
	map<string, int> mp;
	int V, E, v_num = 0;
	int i, j, k;
	fin >> V >> E;
	for (i = 0; i < V; ++i)
	{
		string t;
		fin >> t;
		mp[t] = ++v_num;
	}
	for (i = 0; i < E; ++i)
	{
		string a, b;
		fin >> a >> b;
		M[mp[a]][mp[b]] = 1;
		M[mp[b]][mp[a]] = 1;
	}
	dp[1][1] = 1;
	for (i = 1; i <= V; ++i)
	{
		for (j = i + 1; j <= V; ++j)
		{
			int max_n = 0;
			for (k = 1; k < j; ++k)
			{
				if (M[k][j] && dp[i][k] > 0)
				{
					if (dp[i][k] > max_n)
					{
						max_n = dp[i][k];
					}
				}
			}
			if (max_n > 0)
				dp[i][j] = dp[j][i] = max_n + 1;
		}
	}
	int max_n = 0;
	for (i = 1; i < V; ++i)
	{
		if (M[i][V] && dp[i][V] > 0)
		{
			if (dp[i][V] > max_n)
			{
				max_n = dp[i][V];
			}
		}
	}
	fout << (max_n == 0 ? 1 : max_n) << endl;
	return 0;
}