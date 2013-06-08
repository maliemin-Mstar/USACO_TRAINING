/*----------------------
±©Á¦¡£¡£
----------------------*/
/*
ID: maliemi2
PROG: cowcycle
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

ofstream fout ("cowcycle.out");
ifstream fin ("cowcycle.in");
int fn, rn, f[5], r[10], f_low, f_up, r_low, r_up, ans_f[5], ans_r[10];
double min_v;

void cal()
{
	vector<double> v;
	int i, j;
	for (i = 0; i < fn; ++i)
	{
		for (j = 0; j < rn; ++j)
		{
			v.push_back((double)f[i] / r[j]);
		}
	}
	sort (v.begin(), v.end());
	double mean, diff[50], sum = 0, variance;
	for (i = 0; i < fn * rn - 1; ++i)
	{
		diff[i] = fabs(v[i] - v[i + 1]);
		sum += diff[i];
	}
	mean = sum / (fn * rn - 1);
	sum = 0;
	for (i = 0; i < fn * rn - 1; ++i)
	{
		sum += (diff[i] - mean) * (diff[i] - mean);
	}
	variance = sum / (fn * rn - 1);
	if (variance < min_v)
	{
		min_v = variance;
		for (i = 0; i < fn; ++i)
		{
			ans_f[i] = f[i];
		}
		for (i = 0; i < rn; ++i)
		{
			ans_r[i] = r[i];
		}
	}
}

void dfs_r(int deep, int now)
{
	if (deep == rn)
	{
		if (f[fn - 1] * r[rn - 1] >= 3 * f[0] * r[0])
		{
			cal();
		}
		//cal();
		return;
	}
	for (int i = now; i <= r_up; ++i)
	{
		r[deep] = i;
		dfs_r(deep + 1, i + 1);
	}
}

void dfs_f(int deep, int now)
{
	if (deep == fn)
	{
		dfs_r(0, r_low);
		return;
	}
	for (int i = now; i <= f_up; ++i)
	{
		f[deep] = i;
		dfs_f(deep + 1, i + 1);
	}
}

int main()
{
	fin >> fn >> rn >> f_low >> f_up >> r_low >> r_up;
	min_v = 999999999;
	dfs_f(0, f_low);
	int i;
	for (i = 0; i < fn - 1; ++i)
	{
		fout << ans_f[i] << ' ';
	}
	fout << ans_f[i] << endl;
	for (i = 0; i < rn - 1; ++i)
	{
		fout << ans_r[i] << ' ';
	}
	fout << ans_r[i] << endl;
	return 0;
}