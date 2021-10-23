#include <vector>
#include <queue>

using namespace std;


struct rowArea
{
    int size;
    int locate[2];

    rowArea() {}

    rowArea(int loc)
    {
        size = 1;
        locate[0] = locate[1] = loc;
    }
};

struct area
{
    queue<rowArea> vRa;
    int countOfArea;

    area() {}

    area(rowArea rA) {
        countOfArea = 1;
        vRa.push(rA);
    }
};


queue<rowArea> searchRowArea(int size, int *row)
{
    int i = 0;
    queue<rowArea> rA;

    while (i < size)
    {
        if (row[i] == 1)
        {
            if (i == 0 || row[i - 1] == 1)
                rA.push(rowArea(i));
            else
                rA.back().locate[1]++;
        }
        i++;
    }
    return (rA);
}

vector<area> mergeRowArea(queue <queue<rowArea> > vVRa)
{
    vector<area> ar;
    queue<rowArea> tmp_vRa;

    while (!vVRa.empty())
    {
        tmp_vRa = vVRa.front();
        vVRa.pop();

        if (ar.empty())
        {
            while (!tmp_vRa.empty())
            {
                ar.push_back(tmp_vRa.front());
                tmp_vRa.pop();
            }
        }
        else
        {
            while (!tmp_vRa.empty())
            {
                for (int i = 0; i < ar.size(); i++)
                {
                    if (isOverap(ar[i].vRa.back(), tmp_vRa.front()))
                    {
                        ar[i].vRa.push(tmp_vRa.front());
                        tmp_vRa.pop();
                    }
                }
                ar.push_back(tmp_vRa.front());
            }
            
        }
    }
}

bool    isOverap(rowArea rA1, rowArea rA2)
{
    for (int i = 0; i < rA2.size; i++)
    {
        if (rA1.locate[0] <= i && i <= rA1.locate[1])
            return (true);
    }
    return (false);
}
