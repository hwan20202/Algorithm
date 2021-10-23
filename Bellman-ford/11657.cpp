#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define INF 1e9

typedef	long long ll;
typedef pair<ll,ll> PLL;

int N;
int M;
vector< vector<PLL> >	Elist;
vector<ll>				ans;

int		circuit(void);

int		main(void)
{
	int a;
	int b;
	int c;

	cin >> N >> M;
	Elist.resize(N + 1);
	ans.assign(N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		Elist[a].push_back(make_pair(b, c));
	}
	ans[1] = 0;
	for (int i = 0; i < N - 1; i++)
		circuit();
	if (circuit())
	{
		cout << -1;
		return (0);
	}
	for (int i = 2; i < ans.size(); i++)
	{
		if (ans[i] < INF)
			cout << ans[i] << endl;
		else
			cout << -1 << endl;
	}
	return (0);
}

int		circuit(void)
{
	int dest;
	ll	weight;
	int ret;

	ret = 0;
	for (int i = 1; i < Elist.size(); i++)
	{
		if (ans[i] == INF)
			continue ;
		for (int j = 0; j < Elist[i].size(); j++)
		{
			dest = 	Elist[i][j].first;
			weight = Elist[i][j].second;
			if (ans[dest] > ans[i] + weight)
			{
				ans[dest] = ans[i] + weight;
				ret++;
			}
		}
	}
	return (ret);
}