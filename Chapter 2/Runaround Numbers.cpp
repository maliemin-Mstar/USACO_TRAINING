/*
ID: maliemi2
PROG: runround
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
#define SIZE 22
using namespace std;

ofstream fout ("runround.out");
ifstream fin ("runround.in");

bool is_runaround(int x)
{
	bool num[10];
	memset(num, 0, sizeof(num));
	int t = x, i = log10(x), len = i + 1;;
	string str(i + 1, '0');
	while (t)
	{
		int re = t % 10;
		if (num[re])
			return 0;
		else
			num[re] = 1;
		str[i--] = re + '0';
		t /= 10;
	}
	memset(num, 0, sizeof(num));
	num[str[0] - '0'] = 1;
	int now = 0;
	for (i = 1; i <= len; i++)
	{
		now += str[now] - '0';
		now %= len;
		if (i == len)
		{
			if (!now)
				return 1;
			return 0;
		}
		if (num[str[now] - '0'])
			return 0;
		else
			num[str[now] - '0'] = 1;
	}
}

int main()
{
	int M;
	fin >> M;
	int i;
	for (i = M + 1; ; ++i)
	{
		if (is_runaround(i))
		{
			fout << i << endl;
			break;
		}
	}
	return 0;
}