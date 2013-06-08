/*
ID: maliemi2
PROG: preface
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define SIZE 1010
using namespace std;

ofstream fout ("preface.out");
ifstream fin ("preface.in");
int each_cnt[3500][200], cnt[200], N;

void pro(int x)
{
	int t = x, len;
	while (t)
	{
		len = log10(t);
		if (len == 3)
		{
			each_cnt[x]['M'] += t / 1000;
			t -= t / 1000 * 1000;
		}
		else if (len == 2)
		{
			if (t / 100 <= 3)
				each_cnt[x]['C'] += t / 100;
			else if (t / 100 == 4)
			{
				each_cnt[x]['C']++;
				each_cnt[x]['D']++;
			}
			else if (t / 100 == 5)
			{
				each_cnt[x]['D']++;
			}
			else if (t / 100 > 5 && t / 100 < 9)
			{
				each_cnt[x]['D']++;
				each_cnt[x]['C'] += t / 100 - 5;
			}
			else
			{
				each_cnt[x]['C']++;
				each_cnt[x]['M']++;
			}
			t -= t / 100 * 100;
		}
		else if (len == 1)
		{
			if (t / 10 <= 3)
				each_cnt[x]['X'] += t / 10;
			else if (t / 10 == 4)
			{
				each_cnt[x]['X']++;
				each_cnt[x]['L']++;
			}
			else if (t / 10 == 5)
			{
				each_cnt[x]['L']++;
			}
			else if (t / 10 > 5 && t / 10 < 9)
			{
				each_cnt[x]['L']++;
				each_cnt[x]['X'] += t / 10 - 5;
			}
			else
			{
				each_cnt[x]['X']++;
				each_cnt[x]['C']++;
			}
			t -= t / 10 * 10;
		}
		else
		{
			if (t <= 3)
				each_cnt[x]['I'] += t;
			else if (t == 4)
			{
				each_cnt[x]['I']++;
				each_cnt[x]['V']++;
			}
			else if (t == 5)
			{
				each_cnt[x]['V']++;
			}
			else if (t > 5 && t < 9)
			{
				each_cnt[x]['V']++;
				each_cnt[x]['I'] += t - 5;
			}
			else
			{
				each_cnt[x]['I']++;
				each_cnt[x]['X']++;
			}
			t -= t;
		}
	}
}

void make_sum()
{
	int i;
	for (i = 1; i <= N; ++i)
	{
		cnt['I'] += each_cnt[i]['I'];
		cnt['V'] += each_cnt[i]['V'];
		cnt['X'] += each_cnt[i]['X'];
		cnt['L'] += each_cnt[i]['L'];
		cnt['C'] += each_cnt[i]['C'];
		cnt['D'] += each_cnt[i]['D'];
		cnt['M'] += each_cnt[i]['M'];
	}
}

void print()
{
	if (cnt['I'])
		fout << 'I' << ' ' << cnt['I'] << endl;
	if (cnt['V'])
		fout << 'V' << ' ' << cnt['V'] << endl;
	if (cnt['X'])
		fout << 'X' << ' ' << cnt['X'] << endl;
	if (cnt['L'])
		fout << 'L' << ' ' << cnt['L'] << endl;
	if (cnt['C'])
		fout << 'C' << ' ' << cnt['C'] << endl;
	if (cnt['D'])
		fout << 'D' << ' ' << cnt['D'] << endl;
	if (cnt['M'])
		fout << 'M' << ' ' << cnt['M'] << endl;
}

int main()
{
	memset(each_cnt, 0, sizeof(each_cnt));
	memset(cnt, 0, sizeof(cnt));
	int i, j;
	fin >> N;
	for (i = 1; i <= N; ++i)
	{
		pro(i);
	}
	make_sum();
	print();
	return 0;
}