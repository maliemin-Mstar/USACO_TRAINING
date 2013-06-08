/*
ID: maliemi2
PROG: fence6
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
#define SIZE 220
#define MYMAX 1073741823
#define MYMIN -1073741823
using namespace std;

ofstream fout ("fence6.out");
ifstream fin ("fence6.in");
int mp[SIZE][SIZE], min_s;
vector<int> v[SIZE];
bool mark[SIZE];

void dfs(int start, int now, int sum, int deep)
{
	if (sum && now == start)
	{
		if (sum < min_s)
			min_s = sum;
		return;
	}
	for (int i = 0; i < v[now].size(); ++i)
	{
		if (!mark[v[now][i]] || (v[now][i] == start && deep > 1))
		{
			mark[v[now][i]] = 1;
			dfs(start, v[now][i], sum + mp[now][v[now][i]], deep + 1);
			if (v[now][i] != start)
				mark[v[now][i]] = 0;
		}
	}
}

int main()
{
	int n, k = 1;
	int point[101][101];
	memset (point, 0, sizeof(point));
	memset (mp, 0, sizeof(mp));
	fin >> n;
	int i, j;
	for (i = 0; i < n; ++i)
	{
		int s, ls, n1s, n2s, t[9];
		bool flag = 0;
		fin >> s >> ls >> n1s >> n2s;
		for (j = 0; j < n1s; ++j)
		{
			fin >> t[j];
			if (!point[s][t[j]])
			{
				flag = 1;
				point[s][t[j]] = point[t[j]][s] = k;
			}
		}
		if (flag)
			++k;
		int p1 = point[s][t[0]];
		for (j = 0; j < n1s; ++j)
		{
			for (int l = j + 1; l < n1s; ++l)
			{
				point[t[j]][t[l]] = point[t[l]][t[j]] = p1;
			}
		}
		flag = 0;
		for (j = 0; j < n2s; ++j)
		{
			fin >> t[j];
			if (!point[s][t[j]])
			{
				flag = 1;
				point[s][t[j]] = point[t[j]][s] = k;
			}
		}
		if (flag)
			++k;
		int p2 = point[s][t[0]];
		for (j = 0; j < n2s; ++j)
		{
			for (int l = j + 1; l < n2s; ++l)
			{
				point[t[j]][t[l]] = point[t[l]][t[j]] = p2;
			}
		}
		mp[p1][p2] = mp[p2][p1] = ls;
	}
	for (i = 1; i < k; ++i)
	{
		for (j = 1; j < k; ++j)
		{
			if (mp[i][j])
			{
				v[i].push_back(j);
			}
		}
	}
	min_s = MYMAX;
	for (i = 1; i < k; ++i)
	{
		memset (mark, 0, sizeof(mark));
		mark[i] = 1;
		dfs(i, i, 0, 0);
	}
	fout << min_s << endl;
	return 0;
}