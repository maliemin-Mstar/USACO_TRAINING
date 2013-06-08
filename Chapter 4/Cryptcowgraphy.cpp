/*
ID: maliemi2
PROG: cryptcow
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
#define MYMAX 1073741823
#define MYMIN -1073741823
using namespace std;

ofstream fout ("cryptcow.out");
ifstream fin ("cryptcow.in");
string original;
set <string> st;
int times;
bool flag;

bool sub(string str, int s, int e)
{
	if (s == e)
		return 1;
	int i, j, k;
	for (i = 0; i < 47; ++i)
	{
		if (original[i] == str[s])
		{
			for (j = i + 1, k = s + 1; j < 47 && k < e; ++j, ++k)
			{
				if (original[j] != str[k])
					break;
			}
			if (k == e)
				return 1;
		}
	}
	return 0;
}

bool prefix(string str, int e)
{
	for (int i = 0; i < e; ++i)
	{
		if (original[i] != str[i])
			return 0;
	}
	return 1;
}

bool suffix(string str, int s)
{
	int i, j;
	for (i = 46, j = str.size() - 1; i >= 0 && j >= s; --i, --j)
	{
		if (original[i] != str[j])
			return 0;
	}
	return 1;
}

void dfs(string str, int deep)
{
	if (flag)
		return;
	if (str.size() == 47)
	{
		if (str == original)
		{
			flag = 1;
			times = deep;
		}
		return;
	}
	int i, j;
	for (i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'C' || str[i] == 'O' || str[i] == 'W')
			break;
	}
	if (!prefix(str, i))
		return;
	if (str[i] != 'C')
		return;
	int pre = i + 1, start = i;
	bool cut = 0;
	for (i = pre; i < str.size(); ++i)
	{
		if (str[i] == 'C' || str[i] == 'O' || str[i] == 'W')
		{
			if (!sub(str, pre, i))
			{
				cut = 1;
				break;
			}
			pre = i + 1;
		}
	}
	if (cut)
		return;
	if (str[pre - 1] != 'W')
		return;
	if (!suffix(str, pre))
		return;
	for (j = 0; j < str.size(); ++j)
	{
		if (flag)
			return;
		for (i = 0; i < j; ++i)
		{
			if (flag)
				return;
			for (int k = str.size() - 1; k > j; --k)
			{
				if (flag)
					return;
				if (str[i] == 'C' && str[j] == 'O' && str[k] == 'W')
				{
					string temp;
					for (int l = 0; l < i; ++l)
						temp += str[l];
					for (int l = j + 1; l < k; ++l)
						temp += str[l];
					for (int l = i + 1; l < j; ++l)
						temp += str[l];
					for (int l = k + 1; l < str.size(); ++l)
						temp += str[l];
					if (st.find(temp) == st.end() && st.size() < 50000)   //Ì«¼ÙÁË- -
					{
						st.insert(temp);
						dfs(temp, deep + 1);
					}
				}
			}
		}
	}
}

int main()
{
	original = "Begin the Escape execution at the Break of Dawn";
	times = -1;
	flag = 0;
	char temp[76];
	string str;
	fin.getline(temp, 76);
	str = temp;
	if ((str.size() - 47) % 3 != 0)
	{
		fout << 0 << ' ' << 0 << endl;
		return 0;
	}
	dfs(str, 0);
	if (times == -1)
		fout << 0 << ' ' << 0 << endl;
	else
		fout << 1 << ' ' << times << endl;
	return 0;
}