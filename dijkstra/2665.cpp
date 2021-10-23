#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>

using namespace std;
#define INF 1e9

vector<string> table;
vector< vector<pair<int,int> > > Elist;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<bool>					visited;
vector<int>						dest;

void	dijkstra();

int		main(void)
{
	int	N;

	cin >> N;
	table.resize(N + 1);
	for (int i = 0; i < N; i++)
		table[i].resize(N);
	for (int i = 0; i < N; i++)
		cin >> table[i];
	Elist.resize(N * N);
	visited.assign(N, false);
	dest.assign(N * N, INF);

	int start;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int w;

			start = i * N + j;
			if (i - 1 >= 0)
			{
				w = table[i - 1][j] == '1' ? 0 : 1;
				Elist[start].push_back(make_pair(((i - 1) * N) + j, w));
			}
			if (i + 1 < N)
			{
				w = table[i + 1][j] == '1' ? 0 : 1;
				Elist[start].push_back(make_pair(((i + 1) * N) + j, w));
			}
			if (j - 1 >= 0)
			{
				w = table[i][j - 1] == '1' ? 0 : 1;
				Elist[start].push_back(make_pair((i * N) + (j - 1), w));
			}
			if (j + 1 < N)
			{
				w = table[i][j + 1] == '1' ? 0 : 1;
				Elist[start].push_back(make_pair((i * N) + (j + 1), w));
			}
		}
	}

	dijkstra();
	// cout << "here" << endl;

	// for (int i = 0; i < dest.size(); i++)
	// {
	// 	cout << dest[i] << endl;
	// }

	cout << dest[(N * N) - 1];
    return (0);
}

void	dijkstra()
{
	dest[0] = 0;
	pq.push(make_pair(0, 0));

	while (!pq.empty())
	{
		pair<int, int> current;

		current = pq.top();
		pq.pop();

		if (visited[current.second] == true)
			continue ;
		visited[current.second] = true;

		for (int i = 0; i < Elist[current.second].size(); i++)
		{
			pair<int, int> next;
			next = Elist[current.second][i];
			if (visited[next.first])
				continue;
			if (dest[next.first] > current.first + next.second)
				dest[next.first] = current.first + next.second;
				pq.push(make_pair(dest[next.first], next.first));
		}
	}
	
}