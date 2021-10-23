#include <iostream>
#include <vector>

using namespace std;

void hit(int att_res);
void run(void);
void get_point(void);
void set_num(int cur);
void simul(void);

int ocount;
int point;
vector<int> base(3);
vector<int> team(9, -1);
int N; // inning
vector<int> v;
int maxPoint;

int main(void)
{
    maxPoint = 0;
    cin >> N;
    v.assign(9 * N, 0);
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
    team.at(3) = 0;

    set_num(0);
    cout << maxPoint;
    return (0);
}

void simul()
{
    int att_idx;
    int att_res;

    att_idx = 0;
    point = 0;
    for (int i = 0; i < N; i++)
    {
        ocount = 0;
        base.assign(3, 0);
        while (ocount < 3)
        {
            att_idx  = att_idx % 9;
            att_res = v.at(team.at(att_idx) + (i * 9));
            att_idx++;
            if (att_res == 0)
            {
                ocount++;
                continue;
            }
            hit(att_res);
        }
    }
    if (point > maxPoint)
        maxPoint = point;
}

void hit(int att_res)
{
    int size;

    size = base.size();
    for (int i = 1; i <= size; i++)
    {
        if (base.at(size - i) == 1)
        {
            if (size - i + att_res > 2)
            {
                point++;
                base.at(size - i) = 0;
            }
            else
            {
                base.at(size - i) = 0;
                base.at(size - i + att_res) = 1;
            }
        }
    }
    if (att_res > size)
        point++;
    else
        base.at(att_res - 1) = 1;
}

void set_num(int cur)
{
    int overlap;

    if (cur == 3)
        set_num(cur + 1);
    else
    {
        for(int i = 1; i < team.size(); i++)
        {
            overlap = 0;
            for (int j = 0; j < cur; j++)
            {
                if (team.at(j) == i)
                {
                    overlap = 1;
                    break;
                }
            }
            if (overlap == 1)
                continue;
            team.at(cur) = i;
            if (cur == 8)
                simul();
            else
                set_num(cur + 1);
        }
    }
}