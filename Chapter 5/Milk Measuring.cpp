/*-----------------
我是用背包求出最少的数量 再去搜索字典序的结果
dp[i][j] = min(f[i - 1][j], f[i - 1][j - cost[i]] + 1, f[i - 1][j - 2 * cost[i]] + 1, f[i - 1][j - 3 * cost[i]] + 1, ......)
-----------------*/
/*
ID: maliemi2
PROG: milk4
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
#define SIZE 220
#define NHASH 99991
#define MYMAX 1073741823
#define MYMIN -1073741823
typedef long long LL;
using namespace std;

ofstream fout ("milk4.out");
ifstream fin ("milk4.in");
int co[101], Q, n, dp[20001], cnt, num[5];
bool flag;

bool dfs2(int deep, int sum)//验证这组数据是否ok
{
	if (deep == cnt - 1)
	{
		if ((Q - sum) % num[deep] == 0)
			return 1;
		else
			return 0;
	}
	for (int k = num[deep]; sum + k < Q; k += num[deep])
	{
		if (dfs2(deep + 1, sum + k))
			return 1;
	}
	return 0;
}

void dfs1(int index, int c)//产生一组数据
{
	if (flag)
		return;
	int i;
	if (c == cnt)
	{
		if (dfs2(0, 0))
			flag = 1;
		return;
	}
	for (i = index; i < n; ++i)
	{
		if (flag)
			return;
		num[c] = co[i];
		dfs1(i + 1, c + 1);
	}
}

int main()
{
	flag = 0;
	fin >> Q >> n;
	int i, j;
	for (i = 0; i < n; ++i)
		fin >> co[i];
	sort (co, co + n);
	for (i = 1; i <= Q; ++i)
		dp[i] = MYMAX;
	dp[0] = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = Q; j >= co[i]; --j)
		{
			int min_v = dp[j];
			for (int k = co[i]; k <= j; k += co[i])
			{
				min_v = min(min_v, dp[j - k] + 1);
			}
			dp[j] = min_v;
		}
	}
	cnt = dp[Q];
	dfs1(0, 0);
	fout << cnt;
	for (i = 0; i < cnt; ++i)
		fout << ' ' << num[i];
	fout << endl;
	return 0;
}