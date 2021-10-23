#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9

int				get_idx(int pos_fir, int pos_sec);
pair<int,int>	get_pos(int idx);
void			dijkstra();

// parsing
int M;
int N;

// dijkstra
vector<int>		dest;

vector< vector<int> > map;

int main(void)
{
	char str[100];

	cin >> M >> N;
	map.assign(N, vector<int>(M, 0));
	dest.assign(N * M, INF);
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
			map[i][j] = str[j] - '0';
	}

	dijkstra();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << dest[(i * M) + j] << " ";
		cout << endl;
	}
	cout << endl;
	// cout << dest.back();
	return (0);
}

void			dijkstra()
{
	int cur_idx = 0;
	pair<int,int> cur_pos;

	dest[0] = 0;
	while (cur_idx < dest.size())
	{
		cur_pos = get_pos(cur_idx);
		if (cur_pos.first - 1 >= 0)
			if (dest[get_idx(cur_pos.first - 1, cur_pos.second)] > dest[cur_idx] + map[cur_pos.first - 1][cur_pos.second])
				dest[get_idx(cur_pos.first - 1, cur_pos.second)] = dest[cur_idx] + map[cur_pos.first - 1][cur_pos.second];
		
		if (cur_pos.first + 1 < N)
			if (dest[get_idx(cur_pos.first + 1, cur_pos.second)] > dest[cur_idx] + map[cur_pos.first + 1][cur_pos.second])
				dest[get_idx(cur_pos.first + 1, cur_pos.second)] = dest[cur_idx] + map[cur_pos.first + 1][cur_pos.second];

		if (cur_pos.second - 1 >= 0)
			if (dest[get_idx(cur_pos.first, cur_pos.second - 1)] > dest[cur_idx] + map[cur_pos.first][cur_pos.second - 1])
				dest[get_idx(cur_pos.first, cur_pos.second - 1)] = dest[cur_idx] + map[cur_pos.first][cur_pos.second - 1];

		if (cur_pos.second + 1 < M)
			if (dest[get_idx(cur_pos.first, cur_pos.second + 1)] > dest[cur_idx] + map[cur_pos.first][cur_pos.second + 1])
				dest[get_idx(cur_pos.first, cur_pos.second + 1)] = dest[cur_idx] + map[cur_pos.first][cur_pos.second + 1];
		cur_idx++;
	}
}

int				get_idx(int pos_fir, int pos_sec)
{
	return (pos_fir * M + pos_sec);
}

pair<int,int>	get_pos(int idx)
{
	return (make_pair(idx/M, idx%M));
}