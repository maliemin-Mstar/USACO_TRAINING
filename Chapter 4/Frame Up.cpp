/*---------------
Õÿ∆À≈≈–Ú
--------------*/
/*
ID: maliemi2
PROG: frameup
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
#define NHASH 99991
#define MYMAX 1073741823
#define MYMIN -1073741823
using namespace std;

ofstream fout ("frameup.out");
ifstream fin ("frameup.in");
bool mp[26][26], exist[26];
int ins[26], ans[26], cnt;

struct node
{
	int u, d, l, r;
}letter[26];

void dfs(int deep)
{
	int i, j;
	if (deep == cnt)
	{
		for (i = 0; i < cnt; ++i)
		{
			fout << (char)(ans[i] + 'A');
		}
		fout << endl;
		return;
	}
	for (i = 0; i < 26; ++i)
	{
		if (exist[i] && !ins[i])
		{
			ans[deep] = i;
			exist[i] = 0;
			vector<int> v;
			for (j = 0; j < 26; ++j)
			{
				if (mp[i][j])
				{
					v.push_back(j);
					mp[i][j] = 0;
					--ins[j];
				}
			}
			dfs(deep + 1);
			exist[i] = 1;
			for (j = 0; j < v.size(); ++j)
			{
				mp[i][v[j]] = 1;
				++ins[v[j]];
			}
		}
	}
}

int main()
{
	memset (exist, 0, sizeof(exist));
	memset (mp, 0, sizeof(mp));
	memset (ins, 0, sizeof(ins));
	char arr[31][31];
	int row, col;
	fin >> row >> col;
	int i, j;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			fin >> arr[i][j];
			if (arr[i][j] != '.')
			{
				if (!exist[arr[i][j] - 'A'])
				{
					letter[arr[i][j] - 'A'].u = i;
					letter[arr[i][j] - 'A'].d = i;
					letter[arr[i][j] - 'A'].l = j;
					letter[arr[i][j] - 'A'].r = j;
					exist[arr[i][j] - 'A'] = 1;
				}
				if (i > letter[arr[i][j] - 'A'].d)
					letter[arr[i][j] - 'A'].d = i;
				if (j < letter[arr[i][j] - 'A'].l)
					letter[arr[i][j] - 'A'].l = j;
				if (j > letter[arr[i][j] - 'A'].r)
					letter[arr[i][j] - 'A'].r = j;
			}
		}
	}
	for (i = 0; i < 26; ++i)
	{
		if (exist[i])
		{
			bool mark[26];
			memset (mark, 0, sizeof(mark));
			for (j = letter[i].l; j <= letter[i].r; ++j)
			{
				if (arr[letter[i].u][j] != 'A' + i)
				{
					mp[i][arr[letter[i].u][j] - 'A'] = 1;
					if (!mark[arr[letter[i].u][j] - 'A'])
					{
						mark[arr[letter[i].u][j] - 'A'] = 1;
						++ins[arr[letter[i].u][j] - 'A'];
					}
				}
				if (arr[letter[i].d][j] != 'A' + i)
				{
					mp[i][arr[letter[i].d][j] - 'A'] = 1;
					if (!mark[arr[letter[i].d][j] - 'A'])
					{
						mark[arr[letter[i].d][j] - 'A'] = 1;
						++ins[arr[letter[i].d][j] - 'A'];
					}
				}
			}
			for (j = letter[i].u + 1; j < letter[i].d; ++j)
			{
				if (arr[j][letter[i].l] - 'A' != i)
				{
					mp[i][arr[j][letter[i].l] - 'A'] = 1;
					if (!mark[arr[j][letter[i].l] - 'A'])
					{
						mark[arr[j][letter[i].l] - 'A'] = 1;
						++ins[arr[j][letter[i].l] - 'A'];
					}
				}
				if (arr[j][letter[i].r] - 'A' != i)
				{
					mp[i][arr[j][letter[i].r] - 'A'] = 1;
					if (!mark[arr[j][letter[i].r] - 'A'])
					{
						mark[arr[j][letter[i].r] - 'A'] = 1;
						++ins[arr[j][letter[i].r] - 'A'];
					}
				}
			}
		}
	}
	for (i = 0; i < 26; ++i)
	{
		if (exist[i])
			++cnt;
	}
	dfs(0);
	return 0;
}