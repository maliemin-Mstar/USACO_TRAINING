/*
ID: maliemi2
PROG: butter
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

ofstream fout ("butter.out");
ifstream fin ("butter.in");
int N, P, C, num[810], dis[810][810];

void floyd()
{
	int i, j, k;
	for (k = 1; k <= P; ++k)
	{
		for (i = 1; i <= P; ++i)
		{
			for (j = 1; j <= P; ++j)
			{
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
}

int main()
{
	fin >> N >> P >> C;
	memset(num, 0, sizeof(num));
	int i, j;
	for (i = 1; i <= P; ++i)
	{
		for (j = 1; j <= P; ++j)
		{
			if (i == j)
				dis[i][j] = 0;
			else 
				dis[i][j] = MYMAX;
		}
	}
	for (i = 0; i < N; ++i)
	{
		int t;
		fin >> t;
		num[t]++;
	}
	for (i = 0; i < C; ++i)
	{
		int s, e, l;
		fin >> s >> e >> l;
		dis[s][e] = dis[e][s] = l;
	}
	floyd();
	int min_total = MYMAX;
	for (i = 1; i <= P; ++i)
	{
		int sum = 0;
		for (j = 1; j <= P; ++j)
		{
			if (num[j])
			{
				sum += num[j] * dis[i][j];
			}
		}
		if (sum < min_total)
			min_total = sum;
	}
	fout << min_total << endl;
	return 0;
}