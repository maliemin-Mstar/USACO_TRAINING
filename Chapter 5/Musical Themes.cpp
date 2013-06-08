/*------------------------------
二分啊、、、、我咋想不到捏
二分是好东西。。5555
------------------------------*/
/*
ID: maliemi2
PROG: theme
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
typedef long long LL;
using namespace std;

ofstream fout ("theme.out");
ifstream fin ("theme.in");
int n, diff[5010];

bool found(int len)
{
	int j, k, l;
	for (j = 0; j + 2 * len < n - 1; ++j)
	{
		for (k = j + len + 1; k + len <= n - 1; ++k)
		{
			for (l = 0; l < len; ++l)
			{
				if (diff[j + l] != diff[k + l])
					break;
			}
			if (l == len)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	fin >> n;
	int i, j, t1, t2;
	fin >> t1;
	for (i = 0; i < n - 1; ++i)
	{
		fin >> t2;
		diff[i] = t1 - t2;
		t1 = t2;
	}
	int l = 4, r = n / 2 - 1, ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (found(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	fout << ans + 1 << endl;
	return 0;
}