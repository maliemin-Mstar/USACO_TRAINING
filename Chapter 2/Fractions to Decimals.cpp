/*
ID: maliemi2
PROG: fracdec
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
#define SIZE 22
#define MYMAX 1073741823
using namespace std;

ofstream fout ("fracdec.out");
ifstream fin ("fracdec.in");

int main()
{
	int a, b, quotient, remaind, i, j, tens;
	string ans;
	int remainder[100010];
	memset (remainder, 0, sizeof(remainder));
	fin >> a >> b;
	quotient = a / b;
	if (quotient)
	{
		tens = pow(10, (int)log10(quotient));
		while (tens)
		{
			ans += quotient / tens + '0';
			quotient %= tens;
			tens /= 10;
		}
	}
	else 
		ans += '0';
	ans += '.';
	remaind = a % b;
	if (!remaind)
		ans += '0';
	else
	{
		remainder[remaind] = ans.size();
		while (1)
		{
			remaind *= 10;
			if (remaind >= b)
			{
				ans += remaind / b + '0';
				remaind %= b;
			}
			else 
				ans += '0';
			if (remainder[remaind] || !remaind)
				break;
			remainder[remaind] = ans.size();
		}
		if (remaind)
		{
			remaind *= 10;
			remaind %= b;
			i = remainder[remaind] - 1;
			string temp;
			for (j = 0; j < i; ++j)
				temp += ans[j];
			temp += '(';
			for (j = i; j != ans.size(); ++j)
				temp += ans[j];
			ans = temp;
			ans += ')';
		}
	}
	for (i = 0; i < ans.size(); ++i)
	{
		if (i % 76 == 0 && i)
			fout << endl;
		fout << ans[i];
	}
	fout << endl;
	return 0;
} 