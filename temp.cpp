#include <iostream>

using namespace std;

int main(void)
{
    int width;
    int height;

    cin >> width >> height;
    //circuit
    //validate
}

int board_check(char **board, bool white)
{
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i % 2 == 0) && (j % 2 == 0))
            {
                if (board[i][j] != white)
                    count++;
            }
            else if ((i % 2 == 0) && (j % 2 == 1))
            {
                if (board[i][j] == white)
                    count++;
            }
            else if ((i % 2 == 1) && (j % 2 == 0))
            {
                if (board[i][j] == white)
                    count++;
            }
            else if ((i % 2 == 1) && (j % 2 == 1))
            {
                if (board[i][j] != white)
                    count++;
            }
        }
    }
    return (count);
}