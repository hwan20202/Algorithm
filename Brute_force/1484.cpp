#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//과거 몸무게 : x
//찐 몸무게 : n
//현재 몸무게 : x + n
// (x + y)(x - y) = G

int main()
{
    int G;
    vector<int> v;

    cin >> G;
    for (int past = 0; past < G; past++)
    {
        for(int n = 0; n * n < G; n++)
        {
            if (2 * n * past + n * n == G)
                v.push_back(past + n);
        }
    }
    if (v.size() == 0)
    {
        cout << -1;
        return (0);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return (0);
}