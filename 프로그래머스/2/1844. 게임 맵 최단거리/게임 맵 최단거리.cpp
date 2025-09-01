#include<vector>
#include <queue>
#include <map>
using namespace std;

int BFS(const vector<vector<int>>& maps, int startX, int startY, const int& endX, const int& endY)
{
    int width = maps[0].size();
    int height = maps.size();

    // [y][x]
    int** isVisited = new int* [height];
    for (int i = 0; i < height; ++i)
    {
        isVisited[i] = new int[width];
        for (int j = 0; j < width; ++j)
        {
            isVisited[i][j] = 0;
        }
    }

    // x, y
    queue<pair<int, int>> nodes;
    isVisited[startY][startX] = 1;
    nodes.push(make_pair(startX, startY));

    while (!nodes.empty())
    {
        pair<int, int> p = nodes.front();
        nodes.pop();

        startX = p.first;
        startY = p.second;

        if (startX == endX &&
            startY == endY)
        {
            break;
        }

        if (startX - 1 >= 0 && !isVisited[startY][startX - 1] && maps[startY][startX - 1] == 1)
        {
            isVisited[startY][startX - 1] = isVisited[startY][startX] + 1;
            nodes.push(make_pair(startX - 1, startY));
        }
        if (startY - 1 >= 0 && !isVisited[startY - 1][startX] && maps[startY - 1][startX])
        {
            isVisited[startY - 1][startX] = isVisited[startY][startX] + 1;
            nodes.push(make_pair(startX, startY - 1));
        }
        if (startX + 1 < width && !isVisited[startY][startX + 1] && maps[startY][startX + 1])
        {
            isVisited[startY][startX + 1] = isVisited[startY][startX] + 1;
            nodes.push(make_pair(startX + 1, startY));
        }
        if (startY + 1 < height && !isVisited[startY + 1][startX] && maps[startY + 1][startX])
        {
            isVisited[startY + 1][startX] = isVisited[startY][startX] + 1;
            nodes.push(make_pair(startX, startY + 1));
        }
    }

    int answer = isVisited[height - 1][width - 1];

    for (int i = 0; i < height; ++i)
        delete[] isVisited[i];
    delete[] isVisited;

    return answer;
}


int solution(vector<vector<int> > maps)
{
    int width = maps[0].size();
    int height = maps.size();

    if (width == 1)
    {
        if (maps[height - 1][0] == 0)
            return -1;
    }
    else if (height == 1)
    {
        if (maps[0][width - 1] == 0)
            return -1;
    }
    else
    {
        if (maps[height - 2][width - 1] == 0 &&
            maps[height - 1][width - 2] == 0)
            return -1;
    }

    int answer = 0;

    int endX = width - 1;
    int endY = height - 1;

    answer = BFS(maps, 0, 0, endX, endY);

    return (answer == 0 ? -1 : answer);
}