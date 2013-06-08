/*-------------------------------
http://magicalcode.blogbus.com/logs/37193487.html
------------------------------*/
/*
ID: maliemi2
PROG: job
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

ofstream fout ("job.out");
ifstream fin ("job.in");

int main()
{
	vector<int> va, vb;
	int n, m1, m2, a[31], b[31], ai, bi;
	int i, j;
	fin >> n >> m1 >> m2;
	for (i = 0; i < m1; ++i)
	{
		fin >> a[i];
	}
	for (i = 0; i < m2; ++i)
	{
		fin >> b[i];
	}
	for (i = 1; ; ++i)
	{
		int sum = 0;
		for (j = 0; j < m1; ++j)
		{
			sum += i / a[j];
		}
		if (sum >= n)
		{
			fout << i << ' ';
			ai = i;
			break;
		}
	}
	for (i = 1; ; ++i)
	{
		int sum = 0;
		for (j = 0; j < m2; ++j)
		{
			sum += i / b[j];
		}
		if (sum >= n)
		{
			bi = i;
			break;
		}
	}
	for (i = 0; i < m1; ++i)
	{
		int j = ai / a[i];
		for (; j > 0; --j)
		{
			va.push_back(j * a[i]);
		}
	}
	for (i = 0; i < m2; ++i)
	{
		int j = bi / b[i];
		for (; j > 0; --j)
		{
			vb.push_back(j * b[i]);
		}
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	int max_time = -1;
	for (i = 0; i < n; ++i)
	{
		max_time = max(max_time, va[i] + vb[n - 1 - i]);
	}
	fout << max_time << endl;
	return 0;
}