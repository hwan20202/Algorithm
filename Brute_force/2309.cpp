#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int sumall();
void recursion(int cur, vector<int> *v);
vector<int> s(7);
vector<int> a(7);

int	main()
{
	vector<int> v(9);

	for (int i = 0; i < 9; i++)
		cin >> v[i];
	for (int i = 0; i < 7; i++)
		a[i] = 0;
	recursion(0, &v);

	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	return (0);
}

void recursion(int cur, vector<int> *v)
{
	int tmp;

	for (int i = 0; i < v->size(); i++)
	{
		if (v->at(i) == 101)
			continue ;
		s[cur] = v->at(i);
		tmp = v->at(i);
		(*v)[i] = 101;
		if (cur == 6)
		{
			if (sumall() == 100)
				a = s;
		}
		else
			recursion(cur + 1, v);
		(*v)[i] = tmp;
	}
}

int sumall()
{
	int ret;

	ret = 0;
	for (int i = 0; i < 7; i++)
		ret = ret + s[i];
	return (ret);
}