#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define INF 1e9

typedef long long	ll;
typedef pair<ll,ll>	PLL;

vector< vector< vector<PLL> > > Elist;
int	TC;

int				circuit(vector< vector<PLL> > table, vector<ll> *ans);
void			BF(int idx);

int				main(void)
{
	int			N;
	int			M;
	int			W;

	int			S;
	int			E;
	int			T;

    cin >> TC;
	Elist.resize(TC);
	for (int i = 0; i < TC; i++)
	{
		cin >> N >> M >> W;
		Elist[i].resize(N + 1);
		for (int j = 0; j < M; j++)
		{
			cin >> S >> E >> T;
			Elist[i][S].push_back(make_pair(E, T));
			Elist[i][E].push_back(make_pair(S, T));
		}
		for (int j = 0; j < W; j++)
		{
			cin >> S >> E >> T;
			Elist[i][S].push_back(make_pair(E, -1 * T));
		}
	}
	for (int i = 0; i < TC; i++)
		BF(i);
	return (0);
}

void				BF(int idx)
{
	vector<ll>	ans;
	int			size;

	size = Elist[idx].size();
	ans.assign(size, INF);
	ans[1] = 0;
	for (int i = 0; i < size - 1; i++)
		circuit(Elist[idx], &ans);
	// for (int i = 0; i < ans.size(); i++)
	// 	cout << ans[i] << endl;
	if (circuit(Elist[idx], &ans))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}

int				circuit(vector< vector<PLL> > table, vector<ll> *ans)
{
	int			dest;
	ll			weight;
	int			ret;

	ret = 0;
	for (int i = 1; i < table.size(); i++)
	{
		// if ((*ans)[i] == INF)
		// 	continue ;
		for (int j = 0; j < table[i].size(); j++)
		{
			dest = table[i][j].first;
			weight = table[i][j].second;
			if ((*ans)[dest] > (*ans)[i] + weight)
			{
				(*ans)[dest] = (*ans)[i] + weight;
				ret++;
			}
		}
	}
	return (ret);
}