/*
ID: maliemi2
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 22
using namespace std;

ofstream fout ("holstein.out");
ifstream fin ("holstein.in");

int V, G, vitamin[26], scoop[16][26], min_s = 15, amount_temp[16], sum[26], amount[16];

bool ok()
{
	for (int i = 1; i <= V; i++)
	{
		if (sum[i] < vitamin[i])
			return 0;
	}
	return 1;
}

void dfs (int deep)
{
	if (deep == G + 1)
	{
		if (ok())
		{
			int total = 0;
			for (int i = 1; i <= G; i++)
				total += amount_temp[i];
			if (total < min_s)
			{
				min_s = total;
				for (int i = 1; i <= G; i++)
					amount[i] = amount_temp[i];
			}
		}
		return;
	}
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		int temp[26], j;
		for (j = 1; j <= V; j++)
		{
			temp[j] = sum[j];
			sum[j] += i * scoop[deep][j];
		}
		amount_temp[deep] = i;
		dfs (deep + 1);
		for (j = i; j <= V; j++)
			sum[j] = temp[j];
	}
}

int main()
{
	memset(sum, 0, sizeof(sum));
	memset(amount_temp, 0, sizeof(amount_temp));
	int i, j;
	fin >> V;
	for (i = 1; i <= V; i++)
		fin >> vitamin[i];
	fin >> G;
	for (i = G; i > 0; i--)
	{
		for (j = 1; j <= V; j++)
			fin >> scoop[i][j];
	}
	dfs(1);
	fout << min_s << ' ';
	j = min_s;
	if (j != 1)
	{
		for (i = G; i > 0; i--)
		{
			if (amount[i])
			{
				j--;
				fout << G - i + 1 << ' ';
			}
			if (j == 1)
				break;
		}
		while (!amount[--i]);
		fout << G - i + 1 << endl;
	}
	else
	{
		for (i = G; i > 0; i--)
		{
			if (amount[i])
			{
				fout << G - i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}