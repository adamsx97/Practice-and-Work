/*
ID: nyyl1303
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	int flag[1000010] = {0};
	int n, st, et, ct = 0, id = 0, max = -1, min = 1000000, count, curr;
	//st:starttime, et:endtime, ct:continuous, id:idle
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	fin >> n;
	for (int k = 0; k < n; k++)
	{
		fin >> st >> et;
		max = max > et ? max : et;
		min = min < st ? min : st;
		for (int i = st; i < et; ++i)
			flag[i] = 1;
	} // for()

	count = 0;
	curr = flag[min];
	for (int i = min; i <= max ; i++)
	{
		if (flag[i] == curr)
			count++;
		else
		{
			if (curr == 0)
				id = id > count ? id : count;
			else
				ct = ct > count ? ct : count;
			curr = flag[i];
			count = (i == max) ? 0 : 1;
		} // else()
	} // for(): count largest idle and continuous time
	if (count != 0)
	{
		if (curr == 0)
			id = id > count ? id : count;
		else
			ct = ct > count ? ct : count;
	} // if()
	fout << ct << " " << id << endl;
	return 0;
} // main()
