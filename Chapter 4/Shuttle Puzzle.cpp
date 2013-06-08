/*-------------
题解说可以找规律
但我广搜了。。。
都不需要判重的。。就是说不需要搞个set的
要记录经过的状态 所以我自己实现队列了  我现在不知道还有别的什么方法可以记录的。。。

---------啊。。。官方题解也是找规律。。。看来我必须得搞懂找规律的做法。。。--------
-------------*/
/*
ID: maliemi2
PROG: shuttle
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

ofstream fout ("shuttle.out");
ifstream fin ("shuttle.in");
int n, len, total_deep;
string init, goal;

struct node
{
	string state;
	int pre;
	int move;
};
vector<node> que;
//set<string> st;

int bfs()
{
	node start;
	start.pre = -1;
	start.state = init;
	//st.insert(init);
	que.push_back(start);
	int top = 0;
	while (top < que.size())
	{
		node now = que[top];
		if (now.state == goal)
		{
			return top;
		}
		int i, j, space_index, index;
		node next;
		for (i = 0; i < len; ++i)
		{
			if (now.state[i] == ' ')
				break;
		}
		space_index = i;
		index = space_index - 2;
		if (index >= 0 && now.state[index] == 'w' && now.state[index + 1] == 'b')
		{
			string temp;
			for (i = 0; i < index; ++i)
				temp += now.state[i];
			temp += ' ';
			temp += 'b';
			temp += 'w';
			for (i = index + 3; i < len; ++i)
			{
				temp += now.state[i];
			}
			//if (st.find (temp) == st.end) {st.insert (temp); next.move...   不需要的。。。
			next.move = index;
			next.pre = top;
			next.state = temp;
			que.push_back(next);
		}
		index = space_index - 1;
		if (index >= 0 && now.state[index] == 'w')
		{
			string temp;
			for (i = 0; i < index; ++i)
				temp += now.state[i];
			temp += ' ';
			temp += 'w';
			for (j = i + 2; j < len; ++j)
				temp += now.state[j];
			next.move = index;
			next.pre = top;
			next.state = temp;
			que.push_back(next);
		}
		index = space_index + 1;
		if (index < len && now.state[index] == 'b')
		{
			string temp;
			for (i = 0; i < index - 1; ++i)
				temp += now.state[i];
			temp += 'b';
			temp += ' ';
			for (j = index + 1; j < len; ++j)
				temp += now.state[j];
			next.move = index;
			next.pre = top;
			next.state = temp;
			que.push_back(next);
		}
		index = space_index + 2;
		if (index < len && now.state[index] == 'b' && now.state[index - 1] == 'w')
		{
			string temp;
			for (i = 0; i < index - 2; ++i)
				temp += now.state[i];
			temp += 'b';
			temp += 'w';
			temp += ' ';
			for (i = index + 1; i < len; ++i)
			{
				temp += now.state[i];
			}
			next.move = index;
			next.pre = top;
			next.state = temp;
			que.push_back(next);
		}
		++top;
	}
}

void print(int index, int deep)
{
	if (que[index].pre == - 1)
	{
		total_deep = deep;
		return;
	}
	print(que[index].pre, deep + 1);
	if (!deep || (total_deep - deep) % 20 == 0)
		fout << que[index].move + 1 << endl;
	else
		fout << que[index].move + 1 << ' ';
}

int main()
{
	fin >> n;
	len = 2 * n + 1;
	int i, j;
	for (i = 0; i < n; ++i)
	{
		init += 'w';
		goal += 'b';
	}
	init += ' ';
	goal += ' ';
	for (i = 0; i < n; ++i)
	{
		init += 'b';
		goal += 'w';
	}
	print(bfs(), 0);
	return 0;
}