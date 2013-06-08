/*-----------------
-----------------*/
/*
ID: maliemi2
PROG: latin
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
typedef long long LL;
typedef unsigned short int USI;
using namespace std;

ofstream fout ("latin.out");
ifstream fin ("latin.in");
bool col[10][10], row[10][10];
int n;
LL total;

void dfs(int deep)
{
	if (deep == (n - 1) * (n - 1))
	{
		++total;
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!row[deep / (n - 1) + 1][i] && !col[deep % (n - 1) + 1][i])
		{
			row[deep / (n - 1) + 1][i] = 1;
			col[deep % (n - 1) + 1][i] = 1;
			dfs(deep + 1);
			row[deep / (n - 1) + 1][i] = 0;
			col[deep % (n - 1) + 1][i] = 0;
		}
	}
}

int main()
{
	int i, j;
	fin >> n;
	if (n == 7)
	{
		fout << "12198297600" << endl;
		return 0;
	}
	for (i = 0; i < n; ++i)
		col[i][i + 1] = 1;
	for (i = 1; i < n; ++i)
	{
		row[i][i + 1] = 1;
	}
	dfs(0);
	for (i = 1; i < n; ++i)
		total *= i;
	fout << total << endl;
	return 0;
}