/*
ID: maliemi2
PROG: nocows
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
#define SIZE 22
using namespace std;

ofstream fout ("nocows.out");
ifstream fin ("nocows.in");

int main()
{
	int n, deep, tree[200][100];
	memset (tree, 0, sizeof(tree));
	fin >> n >> deep;
	if (n & 1 == 0)
	{
		fout << 0 <<endl;
		return 0;
	}
	tree[1][1] = 1;
	tree[3][2] = 1;
	int i, j, k, l;
	for (i = 0; i < 100; ++i)
		tree[0][i] = 1;
	for (i = 5; i <= n; i += 2)
	{
		for (j = 3; j <= deep; ++j)
		{
			int sum = 0, sum_temp;
			for (k = 0; k < i; ++k)
			{
				sum_temp = 0;
				for (l = 0; l < j - 1; ++l)
				{
					sum_temp += tree[i - 1 - k][l];
					sum_temp %= 9901;
				}
				sum += sum_temp * tree[k][j - 1];
				sum %= 9901;
			}
			sum *= 2;
			sum %= 9901;
			for (k = 0; k < i; ++k)
			{
				sum += tree[k][j - 1] * tree[i - k - 1][j - 1];
				sum %= 9901;
			}
			tree[i][j] = sum;
		}
	}
	fout << tree[n][deep] << endl;
	return 0;
}