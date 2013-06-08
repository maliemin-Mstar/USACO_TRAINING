/*
Ð´µÄÌ«·³ÁË¡£¡£¡£
*/
/*
ID: maliemi2
PROG: lgame
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
using namespace std;

ofstream fout ("lgame.out");
ifstream fin ("lgame.in");
ifstream fin2 ("lgame.dict");
const int sc[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
string moth, dat[40001], dat3[20001], dat4[20001], dat_temp[20001];
int num[26];

bool ok(string str)
{
	int temp_num[26];
	memset (temp_num, 0, sizeof(temp_num));
	for (int i = 0; i < str.size(); ++i)
	{
		++temp_num[str[i] - 'a'];
	}
	for (int i = 0; i < 26; ++i)
	{
		if (temp_num[i] > num[i])
			return 0;
	}
	return 1;
}

int cal(string str)
{
	int sum = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		sum += sc[str[i] - 'a'];
	}
	return sum;
}

int main()
{
	memset (num, 0, sizeof(num));
	fin >> moth;
	int max_s = -1;
	for (int i = 0; i < moth.size(); ++i)
	{
		++num[moth[i] - 'a'];
	}
	if (moth.size() < 6)
	{
		int k = 0;
		string str;
		fin2 >> str;
		while (str != ".")
		{
			if (str.size() > moth.size())
				;
			else if (ok(str))
			{
				dat[k++] = str;
				int t = cal(str);
				if (t > max_s)
					max_s = t;
			}
			fin2 >> str;
		}
		vector<string> v;
		for (int i = 0; i < k; ++i)
		{
			if (cal(dat[i]) == max_s)
				v.push_back(dat[i]);
		}
		fout << max_s << endl;
		for (int i = 0; i < v.size(); ++i)
		{
			fout << v[i] << endl;
		}
	}
	else if (moth.size() == 6)
	{
		int k = 0, k3 = 0;
		string str;
		fin2 >> str;
		while (str != ".")
		{
			if (str.size() != 7)
			{
				dat[k++] = str;
			}
			if (str.size() == 3)
			{
				dat3[k3++] = str;
			}
			fin2 >> str;
		}
		vector<pair<string, string> > v;
		for (int i = 0; i < k3; ++i)
		{
			if (!ok(dat3[i]))
				continue;
			for (int j = i; j < k3; ++j)
			{
				string temp = dat3[i] + dat3[j];
				if (ok(temp))
				{
					v.push_back(make_pair(dat3[i], dat3[j]));
				}
			}
		}
		if (v.size() == 0)
		{
			int k_temp = 0;
			for (int i = 0; i < k; ++i)
			{
				if (ok(dat[i]))
				{
					dat_temp[k_temp++] = dat[i];
					int t = cal(dat[i]);
					if (t > max_s)
						max_s = t;
				}
			}
			vector<string> v;
			for (int i = 0; i < k_temp; ++i)
			{
				if (cal(dat_temp[i]) == max_s)
					v.push_back(dat_temp[i]);
			}
			fout << max_s << endl;
			for (int i = 0; i < v.size(); ++i)
			{
				fout << v[i] << endl;
			}
		}
		else
		{
			for (int i = 0; i < k; ++i)
			{
				if (dat[i].size() == 6)
				{
					if (ok(dat[i]))
					{
						v.push_back(make_pair(dat[i], ""));
					}
				}
			}
			fout << cal(moth) <<endl;
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); ++i)
			{
				if (v[i].second.size())
				{
					fout << v[i].first << ' ' << v[i].second << endl;
				}
				else 
				{
					fout << v[i].first << endl;
				}
			}
		}
	}
	else 
	{
		int k = 0, k3 = 0, k4 = 0;
		string str;
		fin2 >> str;
		while (str != ".")
		{
			dat[k++] = str;
			if (str.size() == 3)
			{
				dat3[k3++] = str;
			}
			if (str.size() == 4)
			{
				dat4[k4++] = str;
			}
			fin2 >> str;
		}
		int i, j;
		vector<pair<string, string> > v;
		for (i = 0; i < k3; ++i)
		{
			if (!ok(dat3[i]))
				continue;
			for (j = 0; j < k4; ++j)
			{
				string temp;
				temp = dat3[i] + dat4[j];
				if (ok(temp))
				{
					if (dat3[i] < dat4[j])
						v.push_back(make_pair(dat3[i], dat4[j]));
					else
						v.push_back(make_pair(dat4[j], dat3[i]));
				}
			}
		}
		if (v.size())
		{
			for (i = 0; i < k; ++i)
			{
				if (dat[i].size() == 7 && ok(dat[i]))
				{
					v.push_back(make_pair(dat[i], ""));
				}
			}
			fout << cal(moth) <<endl;
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); ++i)
			{
				if (v[i].second.size())
				{
					fout << v[i].first << ' ' << v[i].second << endl;
				}
				else 
				{
					fout << v[i].first << endl;
				}
			}
		}
		else
		{
			vector<string> v;
			for (i = 0; i < k; ++i)
			{
				if (dat[i].size() == 7 && ok(dat[i]))
				{
					v.push_back(dat[i]);
				}
			}
			if (v.size())
			{
				fout << cal(moth) <<endl;
				for (int i = 0; i < v.size(); ++i)
				{
					fout << v[i] << endl;
				}
			}
			else
			{
				vector<pair<string, string> > dat_v;
				for (i = 0; i < k3; ++i)
				{
					if (!ok(dat3[i]))
						continue;
					for (j = i; j < k3; ++j)
					{
						string temp = dat3[i] + dat3[j];
						if (ok(temp))
						{
							dat_v.push_back(make_pair(dat3[i], dat3[j]));
							int t = cal(temp);
							if (t > max_s)
								max_s = t;
						}
					}
				}
				for (i = 0; i < k; ++i)
				{
					if (dat[i].size() != 7 && ok(dat[i]))
					{
						dat_v.push_back(make_pair(dat[i], ""));
						int t = cal(dat[i]);
						if (t > max_s)
							max_s = t;
					}
				}
				vector<pair<string, string> > v;
				for (i = 0; i < dat_v.size(); ++i)
				{
					if (max_s == cal(dat_v[i].first + dat_v[i].second))
						v.push_back(dat_v[i]);
				}
				fout << max_s <<endl;
				for (int i = 0; i < v.size(); ++i)
				{
					if (v[i].second.size())
					{
						fout << v[i].first << ' ' << v[i].second << endl;
					}
					else 
					{
						fout << v[i].first << endl;
					}
				}
			}
		}
	}
	return 0;
}