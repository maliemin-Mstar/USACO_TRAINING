/*
ID: maliemi2
PROG: fact4
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

ofstream fout ("fact4.out");
ifstream fin ("fact4.in");

int main()
{
	int zeros = 0, i, n, num[5000];
	fin >> n;
	int t = 5;
	while (n / t != 0)
	{
		zeros += n / t;
		t *= 5;
	}
	int twos;
	twos = zeros;
	for (i = 1; i <= n; ++i)
	{
		num[i] = i;
	}
	for (t = 5; t <= 3125; t *= 5)
	{
		for (int j = t; j <= n; j += t)
		{
			num[j] /= 5;
		}
	}
	for (i = n / 2 * 2; i >= 1; i -= 2)
	{
		if (twos == 0)
		{
			break;
		}
		while (num[i] % 2 == 0)
		{
			num[i] /= 2;
			twos--;
			if (twos == 0)
			{
				break;
			}
		}
	}
	int p = 1;
	for (i = 1; i <= n; ++i)
	{
		p = p * (num[i] % 10) % 10;
	}
	fout << p << endl;
	return 0;
}