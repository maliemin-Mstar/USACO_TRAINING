/*
ID: maliemi2
PROG: msquare
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

ofstream fout ("msquare.out");
ifstream fin ("msquare.in");
string target;

struct node
{
	string config;
	vector<char> v;
	int step;
};

queue<node> q;

void A(string &a)
{
	string temp = a;
	for (int i = 0; i < a.size(); ++i)
		a[i] = temp[a.size() - 1 - i];
}

void B(string &a)
{
	string temp = a;
	a[0] = temp[3];
	a[7] = temp[4];
	a[1] = temp[0];
	a[2] = temp[1];
	a[3] = temp[2];
	a[4] = temp[5];
	a[5] = temp[6];
	a[6] = temp[7];
}

void C(string &a)
{
	string temp = a;
	a[2] = temp[1];
	a[5] = temp[2];
	a[1] = temp[6];
	a[6] = temp[5];
}

void bfs()
{
	set<string> s;
	string temp;
	node now;
	s.insert("12345678");
	while (q.size())
	{
		now = q.front();
		q.pop();
		if (now.config == target)
		{
			fout << now.v.size() << endl;
			for (int i = 0; i < now.v.size(); ++i)
				fout << now.v[i];
			fout << endl;
			return;
		}
		temp = now.config;
		A(temp);
		if (s.find(temp) == s.end())
		{
			s.insert(temp);
			node next;
			next.config = temp;
			next.step = now.step + 1;
			for (int i = 0; i < now.v.size(); ++i)
				next.v.push_back(now.v[i]);
			next.v.push_back('A');
			q.push(next);
		}
		temp = now.config;
		B(temp);
		if (s.find(temp) == s.end())
		{
			s.insert(temp);
			node next;
			next.config = temp;
			next.step = now.step + 1;
			for (int i = 0; i < now.v.size(); ++i)
				next.v.push_back(now.v[i]);
			next.v.push_back('B');
			q.push(next);
		}
		temp = now.config;
		C(temp);
		if (s.find(temp) == s.end())
		{
			s.insert(temp);
			node next;
			next.config = temp;
			next.step = now.step + 1;
			for (int i = 0; i < now.v.size(); ++i)
				next.v.push_back(now.v[i]);
			next.v.push_back('C');
			q.push(next);
		}
	}
}

int main()
{
	char t;
	while (fin >> t)
		target += t;
	node start;
	start.config = "12345678";
	start.step = 0;
	q.push(start);
	bfs();
	return 0;
}