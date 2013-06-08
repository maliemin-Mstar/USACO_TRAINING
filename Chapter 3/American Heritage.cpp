/*
ID: maliemi2
PROG: heritage
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

ofstream fout ("heritage.out");
ifstream fin ("heritage.in");
string mid, pre;
//bool mark[30];
int idex;

void solve(int begin, int end)
{
	if (begin == end)
		return;
	++idex;
	for (int i = begin; i < end; ++i)
	{
		if (mid[i] == pre[idex])
		{
			//mark[i] = 1;
			solve (begin, i);
			solve (i + 1, end);
			fout << mid[i];
			break;
		}
	}
}

int main()
{
	idex = -1;
	fin >> mid >> pre;
	//memset (mark, 0, sizeof(mark));
	solve(0, mid.size());
	fout << endl;
	return 0;
}