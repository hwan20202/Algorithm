#include <iostream>
#include <vector>
using namespace std;

int		infection();
int 	checkall(int idx);
int		check_up(int idx);
int		check_down(int idx);
int		check_left(int idx);
int		check_right(int idx);
void	recursion(int cur);
void	putwall(void);
void	calc(void);


int			row = 0;
int			col = 0;
vector<int>	orig;
vector<int>	v;
vector<int>	pos(3);
int			ans = 0;

int			main()
{
	cin >> row;
	cin >> col;
	orig.assign(row * col, 0);
	for (int i = 0; i < row * col; i++)
		cin >> orig[i];
	v = orig;
	recursion(0);
	
	cout << ans;
}

void		recursion(int cur)
{
	int		overlap;

	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) != 0)
			continue ;
		overlap = 0;
		for (int j = 0; j < cur; j++)
		{
			if (pos.at(j) == i)
				overlap = 1;
		}
		if (overlap == 1)
			continue;
		pos.at(cur) = i;
		if (cur == 2)
		{
			putwall(); //put wall in map;
			int k = 0;
			while (infection())
				k++;
			calc();
			v = orig;
		}
		else
			recursion(cur + 1);
	}
}

void		calc(void)
{
	int 	ret = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == 0)
			ret++;
	}
	if (ret > ans)
		ans = ret;
}

void		putwall()
{
	for(int i = 0; i < pos.size(); i++)
		v.at(pos.at(i)) = 1;
}

int			infection()
{
	int inchange = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == 0)
			inchange += checkall(i);
	}
	return (inchange);
}

/*
** check 4 direction
*/
int checkall(int idx)
{
	int inchange = 0;
	int (*check[4])(int idx);

	check[0] = check_up;
	check[1] = check_down;
	check[2] = check_left;
	check[3] = check_right;

	for(int i = 0; i < 4; i++)
	{
		inchange = check[i](idx);
		if (inchange == 1)
			return (inchange);
	}
	return (inchange);
}

int	check_up(int idx)
{
	int quot;
	int up;
	
	quot = idx / col;
	if (quot > 0)
	{
		up = v.at(idx - col);
		if (up == 2)
		{
			v.at(idx) = 2;
			return (1);
		}
	}
	return (0);
}

int	check_down(int idx)
{
	int quot;
	int down;
	
	quot = idx / col;
	if (quot < row - 1)
	{
		down = v.at(idx + col);
		if (down == 2)
		{
			v.at(idx) = 2;
			return (1);
		}
	}
	return (0);
}

int	check_left(int idx)
{
	int remain;
	int left;
	
	remain = idx % col;
	if (remain > 0)
	{
		left = v.at(idx - 1);
		if (left == 2)
		{
			v.at(idx) = 2;
			return (1);
		}
	}
	return (0);
}

int	check_right(int idx)
{
	int remain;
	int right;
	
	remain = idx % col;
	if (remain < col - 1)
	{
		right = v.at(idx + 1);
		if (right == 2)
		{
			v.at(idx) = 2;
			return (1);
		}
	}
	return (0);
}