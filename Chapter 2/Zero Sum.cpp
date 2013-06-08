/*
ID: maliemi2
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#define SIZE 1010
using namespace std;

ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");
int n;
vector<string> sequence;
string ans;

bool is_zero()
{
	int sum = 0, i, j, pre = 0, num, ten = 10;
	for (i = 0; i < 2 * n - 1; i++)
	{
		while (ans[i] != '-' && ans[i] != '+' && i < 2 * n - 1)
			i++;
		num = 0;
		for (j = pre; j < i; ++j)
		{
			if (ans[j] != ' ')
			{
				num *= 10;
				num += ans[j] - '0';
			}
		}
		if (!pre || ans[pre - 1] == '+')
			sum += num;
		else 
			sum -= num;
		pre = i + 1;
	}
	if (!sum)
		return 1;
	return 0;
}

void dfs(int num, int index)
{
	ans[index] = num - 0 + '0';
	if (num == n)
	{
		if (is_zero())
			sequence.push_back(ans);
		return;
	}
	ans[index + 1] = ' ';
	dfs(num + 1, index + 2);
	ans[index + 1] = '+';
	dfs(num + 1, index + 2);
	ans[index + 1] = '-';
	dfs(num + 1, index + 2);
}

bool cmp(const string &a, const string &b)
{
	return a < b;
}

int main()
{
	fin >> n;
	ans = "1-2 3-4 5+6 7";
	is_zero();
	ans = string(2 * n - 1, '0');
	dfs(1, 0);
	sort(sequence.begin(), sequence.end(), cmp);
	for (vector<string>::iterator i = sequence.begin(); i != sequence.end(); ++i)
		fout << *i << endl;
	return 0;
}