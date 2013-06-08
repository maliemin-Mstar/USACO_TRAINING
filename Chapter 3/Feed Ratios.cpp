/*
ID: maliemi2
PROG: ratios
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

ofstream fout ("ratios.out");
ifstream fin ("ratios.in");
int A[3][3], c[3], x[3], ans[4];

int get_det(int a[3][3])
{
	return a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][0] * a[1][2] * a[2][1] - a[0][1] * a[1][0] * a[2][2] - a[0][2] * a[1][1] * a[2][0];
}

int main()
{
	int i, j, k, l;
	for (i = 0; i < 3; ++i)
		fin >> c[i];
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			fin >> A[j][i];
		}
	}
	int det = get_det(A);
	if (det == 0)
	{
		fout << "NONE" << endl;
	}
	else
	{
		int up = 100 * (A[0][0] + A[0][1] + A[0][2]) / c[0];
		int min = 400;
		for (i = 1; i <= up; ++i)
		{
			if (min != 400 && i % ans[3] == 0)
				continue;
			bool flag = 1;
			for (j = 0; j < 3; ++j)
			{
				int temp[3][3];
				for (k = 0; k < 3; ++k)
				{
					for (l = 0; l < 3; ++l)
					{
						if (k == j)
							temp[l][k] = i * c[l];
						else
							temp[l][k] = A[l][k];
					}
				}
				int t = get_det(temp);
				if (t % det != 0 || t / det > 99 || t / det < 0)
				{
					flag = 0;
					break;
				}
				else
					x[j] = t / det;
			}
			if (flag)
			{
				int t = x[0] + x[1] + x[2];
				if (t < min)
				{
					min = t;
					ans[0] = x[0];
					ans[1] = x[1];
					ans[2] = x[2];
					ans[3] = i;
				}
			}
		}
		if (min == 400)
			fout << "NONE" << endl;
		else
		{
			for (i = 0; i < 3; ++i)
				fout << ans[i] << ' ';
			fout << ans[3] << endl;
		}
	}
	return 0;
}