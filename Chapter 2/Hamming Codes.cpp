/*
ID: maliemi2
PROG: hamming
LANG: C++
*/
#include<iostream>
#include<queue>
#include <fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define SIZE 22
typedef unsigned char uc;
using namespace std;

ofstream fout ("hamming.out");
ifstream fin ("hamming.in");

int N, B, D, num[100] = {-1}, flag = 0;
uc up;

bool is_hamming(uc a, uc b)
{
	uc n = a ^ b;
	uc i;
	for (i = 0; n; i++)
		n &= n - 1;
	if (i >= D)
		return 1;
	return 0;
}

bool all(int x, int deep)
{
	for (int i = 1; i < deep; i++)
	{
		if (!is_hamming(x, num[i]))
			return 0;
	}
	return 1;
}

void dfs(int deep)
{
	if (flag)
		return;
	if (deep == N + 1)
	{
		int i;
		for (i = 1; i < N; i++)
		{
			if (i % 10 == 0)
				fout << num[i] << endl;
			else
				fout << num[i] << ' ';
		}
		fout << num[i] << endl;
		flag = 1;
	}
	int i;
	for (i = num[deep - 1] + 1; i <= up; i++)
	{
		if (deep == 1)
		{
			num[deep] = i;
			dfs(2);
		}
		else
		{
			if (all(i, deep))
			{
				num[deep] = i;
				dfs(deep + 1);
			}
		}
	}
}

int main()
{
	fin >> N >> B >> D;
	int temp = 1 << B;
	up = temp - 1;
	dfs(1);
	return 0;
}