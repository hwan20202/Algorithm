//N 연산의 갯수
//연산 branch, merge

//branch 일 경우 숫자를 하나 덧붙인다.
//merge 일 경우 해당 숫자를 떼어내어 준비 단계에 붙인다.(priority queue)

// strcmp

#include <queue>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

typedef struct {
    char operation[10];
    int branchnum;
} query;

priority_queue<int, vector<int>, greater<int> > usable_pq;
list<int> current_branch;

void solution(int n, query *queries)
{
    current_branch.push_back(1);
    for (int i = 0; i < n; i++ )
    {
        if (queries[i].operation == "branch")
        {
            if (usable_pq.empty())
                current_branch.push_back(/*max()++*/);
            else
            {
                current_branch.push_back(usable_pq.top());
                usable_pq.pop();
            }
        }
        else if (queries[i].operation == "merge")
        {
            //erase_num_in_cur_branch()
            usable_pq.push(queries[i].branchnum);
        }
    }
}

int max_num_in_cur_branch(list<int> cur_branch)
{
    for (int i =0; i < current_branch.size(); i++)
    {
        current_branch.
    }
    
}

//void erase_num_in_cur_branch(list<int> cur_branch)