#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define INF 999999999999

void					dijkstra(int start);

// util
typedef long long		ll;
typedef pair<ll,ll>		PLL;

// parse
int						V;
int						E;
vector< vector<PLL> >	Elist;
vector<int>				Ylist(10, 0);
int						my;

// dijkstra
vector<ll>				dest;
vector<bool>			visited;
priority_queue<PLL, vector<PLL>, greater<PLL> >		pq;

// ans
ll	Ytime = 0;
vector<int>				ans;

int		main(void)
{
	/*
	**	parsing
	*/
	int	u;
	int	v;
	int	w;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	Elist.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		Elist[u].push_back(make_pair(w, v));
		Elist[v].push_back(make_pair(w, u));
	}
	for (int j = 0; j < 10; j++)
		cin >> Ylist[j];
    cin >> my;

	/*
	** core
	*/
	int cur_node;
	int dest_node;

	cur_node = Ylist[0];
	for (int x = 1; x < 10; x++)
	{
		if (cur_node == my)
			ans.push_back(cur_node);
		dest.assign(10001, INF);
		visited.assign(10001, false);
		dest_node = Ylist[x];
		dijkstra(dest_node);
		if (dest[cur_node] == INF)
			continue;
		Ytime += dest[cur_node];
		cur_node = dest_node;
		if (dest[my] == INF)
			continue;
		if (dest[my] <= Ytime)
			ans.push_back(dest_node);
	}

	/*
	** print answer
	*/

	if (ans.empty())
	{
		cout << -1;
		return (0);
	}
	sort(ans.begin(), ans.end());
	cout << ans[0];
	return (0);
}

void				dijkstra(int start)
{
	dest[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		PLL current = pq.top();
		pq.pop();

		if (visited[current.second] == true)
			continue;
		visited[current.second] = true;

		for (int i = 0; i < Elist[current.second].size(); i++)
		{
			PLL next = Elist[current.second][i];
			if (visited[next.second] == true)
				continue;
			if (dest[next.second] < current.first + next.first)
				continue;
			dest[next.second] = current.first + next.first;
			pq.push(make_pair(dest[next.second], next.second));
		}
	}
}