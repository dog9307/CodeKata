#include <string>
#include <vector>

#include <queue>
#include <algorithm>

using namespace std;

struct Point
{
    int i;
    int j;
};

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    vector<vector<bool>> vCheck(maps.size(), vector<bool>(maps[0].size(), false));
    Point deltaP[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (vCheck[i][j]) continue;
            if (maps[i][j] == 'X')
            {
                vCheck[i][j] = true;
                continue;
            }
            else
            {
                queue<Point> q;
                int sum = 0;
                q.push({ i, j });
                while (!q.empty())
                {
                    Point p = q.front();
                    q.pop();

                    if (vCheck[p.i][p.j]) continue;

                    sum += (maps[p.i][p.j] - '0');
                    vCheck[p.i][p.j] = true;

                    for (int k = 0; k < 4; ++k)
                    {
                        Point nP = { p.i + deltaP[k].i, p.j + deltaP[k].j };
                        if (nP.i < 0 || nP.i >= maps.size()) continue;
                        if (nP.j < 0 || nP.j >= maps[nP.i].size()) continue;
                        if (vCheck[nP.i][nP.j]) continue;
                        if (maps[nP.i][nP.j] == 'X')
                        {
                            vCheck[nP.i][nP.j] = true;
                            continue;
                        }

                        q.push(nP);
                    }
                }

                answer.push_back(sum);
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }

    return answer;
}