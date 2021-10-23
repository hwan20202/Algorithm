#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9

void dijkstra(int start);


vector<bool>			visited;
vector<int>				cost;
vector< vector<int> >	path;
vector<int>				K_node;
int K;

struct	node
{
	int current;
	int weight;

	node() {}

	node(int _cur, int _wei)
	{
		current = _cur;
		weight = _wei;
	}
};

struct		compare
{
	bool	operator()(node &a, node &b)
	{
		return (a.weight > b.weight);
	}
};

priority_queue<node, vector<node>, compare> pq;

int main()
{
    int N;
    int M;
    int X;
    int start;
    int end;

    cin >> N;
    cin >> M;

    path.assign(M, vector<int>(2, 0));
	visited.assign(N + 1, false);
	cost.assign(N + 1, INF);

    cin >> K;
    cin >> X;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 2; j++)
			cin >> path[i][j];
    }

	dijkstra(X);

	int count = 0;
	for (int i = 0; i < cost.size(); i++)
	{
		if (cost[i] == K)
		{
			cout << i << endl;
			count++;
		}
	}
	if (count == 0)
		cout << -1;
	return (0);
}

void dijkstra(int start)
{
	node current;

	cost[start] = 0;
	pq.push(node(start, 0));
	while (!pq.empty())
	{
		current = pq.top(); 
		pq.pop();

		if (visited[current.current])
			continue;

		visited[current.current] = true;
		for (int i = 0; i < path.size(); i++)
		{
			node nn;
			int	next = path[i][1];
			if (path[i][0] == current.current)
				nn.current = next;
			else
				continue;
			if (visited[next] == true)
				continue;
			if (cost[next] < current.weight + 1 || K < current.weight + 1)
				continue;

			cost[next] = current.weight + 1;
			nn.weight = current.weight + 1;
			pq.push(nn);
		}
	}
}


