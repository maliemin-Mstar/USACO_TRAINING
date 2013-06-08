/*
ID: maliemi2
PROG: fence9
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

ofstream fout ("fence9.out");
ifstream fin ("fence9.in");

double k1, k2, b;

double get_1(int x)
{
	return k1 * x;
}

double get_2(int x)
{
	return k2 * x + b;
}

int main()
{
	int n, m, p;
	fin >> n >> m >> p;
	k1 = (double)m / n;
	int i, j, cnt = 0;
	if (n != p && n != 0)
	{
		k2 = (double)m / (n - p);
		b = -1.0 * k2 * p;
		if (n < p)
		{
			int l = 1, r = p - 1;
			j = 1;
			while (j < m)
			{
				while (get_1(l) <= j)
					l++;
				while (get_2(r) <= j)
					r--;
				if (r >= l)
					cnt += r - l + 1;
				j++;
			}
		}
		else
		{
			for (i = 1; i < n; ++i)
			{
				for (j = 1; j < m; ++j)
				{
					if (get_1(i) > j && get_2(i) < j)
						cnt++;
				}
			}
		}
	}
	else if (n == 0)
	{
		k2 = (double)m / (n - p);
		b = -1.0 * k2 * p;
		int r = p - 1;
		j = 1;
		while (j < m)
		{
			while (get_2(r) <= j)
				r--;
			if (r >= 1)
				cnt += r;
			j++;
		}
	}
	else 
	{
		for (i = 1; i < p; ++i)
		{
			for (j = 1; j < m; ++j)
			{
				if (get_1(i) > j)
					cnt++;
			}
		}
	}
	fout << cnt << endl;
	return 0;
}