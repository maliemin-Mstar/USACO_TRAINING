/*
ID: maliemi2
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 1010
using namespace std;

ofstream fout ("sort3.out");
ifstream fin ("sort3.in");

int sorted[SIZE], now[SIZE], n;

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	fin >> n;
	int i, j, t, ans = 0;
	for (i = 1; i <= n; i++)
	{
		fin >> now[i];
		sorted[i] = now[i];
	}
	sort (sorted + 1, sorted + n + 1, cmp);
	for (i = n; i > 0; i--)
	{
		if (now[i] != sorted[i])
		{
			for (j = i - 1; j > 0; j--)
			{
				if (now[j] != sorted[j] && now[i] != now[j] && now[i] == sorted[j] && now[j] == sorted[i])
				{
					t = now[i];
					now[i] = now[j];
					now[j] = t;
					ans++;
					break;
				}
			}
		}
	}
	for (i = 1; i <= n && sorted[i] == 1; i++)
	{
		if (now[i] != 1)
			ans += 2;
	}
	fout << ans << endl;
	return 0;
}