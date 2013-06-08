/*
ID: maliemi2
PROG: contact
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

ofstream fout ("contact.out");
ifstream fin ("contact.in");

bool cmp (const string &a, const string &b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	int a, b, n;
	string str, t;
	fin >> a >> b >> n;
	while (fin >> t)
		str += t;
	int i, j, k;
	map<string, int> mp;
	map<int, vector<string> > mp2;
	for (i = a; i <= b && i <= str.size(); ++i)
	{
		for (j = 0; j < str.size() - i + 1; ++j)
		{
			string temp;
			for (k = j; k < j + i; ++k)
				temp += str[k];
			mp[temp]++;
		}
	}
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
		mp2[it->second].push_back(it->first);
	i = 0;
	for (map<int, vector<string> >::reverse_iterator it = mp2.rbegin(); it != mp2.rend() && i < n; ++it, ++i)
	{
		fout << it->first << endl;
		sort (it->second.begin(), it->second.end(), cmp);
		for (j = 0; j < it->second.size() - 1; ++j)
		{
			if (j % 6 == 5)
				fout << (it->second)[j] << endl;
			else
				fout << (it->second)[j] << ' ';
		}
		fout << (it->second)[j] << endl;
	}
	return 0;
}