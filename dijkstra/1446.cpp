#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	set_table(vector<int> node, vector< vector<int> > shortpath);
int		next_node(int arrive, vector<int> node);
void dikjstra(void);

vector < vector<int> > 	table;

int	main(void)
{
	int	N;
	int target;
	vector < vector<int> >	shortpath;
	vector <int>			node;

	cin >> N;
	shortpath.assign(N, vector<int>(3, 0));
	cin >> target;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
				cin >> shortpath[i][j];
	}
	int same;

	// node init();
	node.push_back(0);
	for (int i = 0; i < shortpath.size(); i++)
	{
		same = 0;
		for (int j = 0; j < node.size(); j++)
		{
			if (node.at(j) == shortpath[i][0])
				same = 1;
		}
		if (same == 0)
			node.push_back(shortpath[i][0]);
	}
	node.push_back(target);

	sort(node.begin(), node.end());
	while (node.back() > target)
		node.pop_back();
	// table init();
	table.assign(node.size(), vector<int> (node.size(), 0));

	//table set();
	set_table(node, shortpath);
	dikjstra();
	cout << table.at(0).back();
	return (0);
}

void	set_table(vector<int> node, vector< vector<int> > shortpath)
{
	int next;
	for (int cur = 0; cur < table.size(); cur++)
	{
		for (int other = 0; other < table.at(cur).size(); other++)
		{
			if (other <= cur)
				table.at(cur).at(other) = 0;
			else
			{
				table.at(cur).at(other) = node.at(other) - node.at(cur); //default
				for (int i = 0; i < shortpath.size(); i++)
				{
					if (node.at(cur) == shortpath.at(i).at(0))
					{
						next = next_node(shortpath.at(i).at(1), node);
						if (next_node(shortpath.at(i).at(1), node) < 0)
						 	continue;
						else if (table.at(cur).at(next) > shortpath.at(i).at(2) + node.at(other) - shortpath.at(i).at(1))
						{
								table.at(cur).at(next) = shortpath.at(i).at(2) + node.at(next) - shortpath.at(i).at(1);
						}
					}
				}
			}
		}
	}
}

int		next_node(int arrive, vector<int> node)
{
	for (int i = 0; i < node.size(); i++)
	{
		if (arrive <= node.at(i))
			return (i);
	}
	return (-1);
}

void dikjstra()
{
	for (int cur = 1; cur < table.size(); cur++)
	{
		for (int i = cur; i < table.at(cur).size(); i++)
		{
			if (table.at(0).at(cur) + table.at(cur).at(i) < table.at(0).at(i))
				table.at(0).at(i) = table.at(0).at(cur) + table.at(cur).at(i);
		}
	}
}