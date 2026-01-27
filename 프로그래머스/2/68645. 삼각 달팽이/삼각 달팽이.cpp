#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<int> solution(int n) {
    int sum = n * (n + 1) / 2;
    vector<int> answer(n * (n + 1) / 2, -1);
    // dir : 0 == down, 1 == right, 2 == up
    //                 dR dC
    const int DOWN = 0;
    const int RIGHT = 1;
    const int UP = 2;
    int dir[3][2] = { {1, 0}, {0, 1}, {-1, -1} };
    int curDir = 0;
    int curRow = 0;
    int curCol = 0;
    for (int i = 1; i <= sum; ++i)
    {
        int index = curRow * (curRow + 1) / 2 + curCol;
        answer[index] = i;

        curRow += dir[curDir][0];
        curCol += dir[curDir][1];
        index = curRow * (curRow + 1) / 2 + curCol;

        if (curDir == DOWN && (curRow >= n || answer[index] != -1))
        {
            --curRow;
            ++curCol;
            curDir = RIGHT;
        }
        else if (curDir == RIGHT && (curCol >= n || answer[index] != -1))
        {
            curCol = curCol - 2;
            --curRow;
            curDir = UP;
        }
        else if (curDir == UP && answer[index] != -1)
        {
            curRow -= dir[curDir][0];
            curCol -= dir[curDir][1];
            ++curRow;
            curDir = DOWN;
        }
    }

    return answer;
}