#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

void dijkstra(int start);
void dijkstraT(int start);

struct  node 
{
	int cur;
	int weight;

	node() {}

	node(int _cur, int _weight)
	{
		cur = _cur;
		weight = _weight;
	}
};

struct compare
{
	bool operator()(node &a, node &b)
	{
		return (a.weight > b.weight);
	}
};

vector<int>		ans;
vector<int>		dest;
vector<bool>	visited;
priority_queue<node, vector<node>, compare> pq;
vector< vector <int> > path;

int			main(void)
{
	int		N;
	int		M;
	int		X;
	int 	tmp;

	cin >> N;
	cin >> M;
	cin >> X;

	ans.assign(N, 0);
	//init;
	dest.assign(N, INF);
	visited.assign(N, false);

	path.assign(M, vector<int>(3, 0));
	for (int i = 0; i < M ; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> tmp;
			if (j < 2)
				path[i][j] = tmp - 1;
			else
				path[i][j] = tmp;
		}
	}

	// for (int i = 0; i < N; i++)
	// {
	// 	dijkstra(i);
	// 	if (i == X - 1)
	// 	{
	// 		for (int j = 0; j < N; j++)
	// 			ans[j] += dest[j];
	// 	}
	// 	else
	// 		ans[i] += dest[X - 1];
	// 	// for (int i = 0; i < dest.size(); i++)
	// 	// 	cout << dest[i] << endl;
	// 	// cout << endl;
	// 	dest.assign(N, INF);
	// 	visited.assign(N, false);
	// }
	dijkstra(X - 1);
	for (int i = 0; i < N; i++)
		ans[i] = dest[i];
	dest.assign(N, INF);
	visited.assign(N, false);
	dijkstraT(X - 1);
	for (int i = 0; i < N; i++)
		ans[i] += dest[i];

	sort(ans.begin(), ans.end());
	// for (int i = 0; i < N; i++)
	// 	cout << ans[i] << endl;
	cout << ans.back();
	return(0);
}

void dijkstra(int start)
{
	dest[start] = 0;
	pq.push(node(start, 0));

	while (!pq.empty())
	{
		node current = pq.top();
		pq.pop();

		if (visited[current.cur] == true)
			continue ;
		visited[current.cur] = true;

		// cout << "A";
		for (int i = 0; i < path.size(); i++)
		{
			// cout << path.size();
			if (path[i][0] != current.cur)
				continue;
			int next = path[i][1];
			if (visited[next] == true)
				continue;
			node nn;
			int cost = path[i][2];
			if (dest[next] < current.weight + cost)
				continue;

			nn.cur = next;
			dest[next] = current.weight + cost;
			// cout << dest[next];
			nn.weight = current.weight + cost;
			pq.push(nn);
		}
	}
}

void dijkstraT(int start)
{
	dest[start] = 0;
	pq.push(node(start, 0));

	while (!pq.empty())
	{
		node current = pq.top();
		pq.pop();

		if (visited[current.cur] == true)
			continue ;
		visited[current.cur] = true;

		// cout << "A";
		for (int i = 0; i < path.size(); i++)
		{
			// cout << path.size();
			if (path[i][1] != current.cur)
				continue;
			int next = path[i][0];
			if (visited[next] == true)
				continue;
			node nn;
			int cost = path[i][2];
			if (dest[next] < current.weight + cost)
				continue;

			nn.cur = next;
			dest[next] = current.weight + cost;
			// cout << dest[next];
			nn.weight = current.weight + cost;
			pq.push(nn);
		}
	}
}