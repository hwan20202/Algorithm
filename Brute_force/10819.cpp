
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void calc(vector<int> t);
void	recursion(vector<int> *v, int cur);

vector<int> t;
int out;

int	main()
{
	int res;
	int ans=0, N; cin >> N;
	t = vector<int>(N);
	vector<int> v(N);

	res = 0;
	for (int i = 0; i < N; ++i)
         cin >> v[i];
	recursion(&v, 0);

    cout << out << "\n";
    return 0;
}

void	recursion(vector<int> *v, int cur)
{
	int tmp;
	for(int i = 0; i < t.size(); i++)
	{
		if ((*v).at(i) == 1234)
			continue;
		// printf("=== rec deep : %d ===\n", cur);
		tmp = (*v).at(i);
		t.at(cur) = tmp;
		(*v).at(i) = 1234;
		if (t.size() - cur > 1)
			recursion(v, cur + 1);
		else
			calc(t);
		(*v).at(i) = tmp;
	}
}

void calc(vector<int> t)
{
	int ret;
	int tmp;

	ret = 0;
	for(int i = 0; i < t.size() - 1; i++)
	{
		tmp = 0;
		// printf("=== %d, %d ===\n", t.at(i), t.at(i + 1));
		tmp = t.at(i) - t.at(i + 1);
		if (tmp < 0)
			tmp = tmp * -1;
		ret = ret + tmp;
	}
	if (out < ret)
		out = ret;
}
