#include <string>
#include <vector>

using namespace std;

int Clamp(const int& v, const int& min, const int& max)
{
    int temp = v;
    if (temp < min)
    {
        temp = min;
    }
    
    if (temp > max)
    {
        temp = max;
    }
    
    return temp;
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    int MaxHP = health;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];

    int idx = 0;
    int curAtkT = -1;
    int curDmg = -1;
    int curT = 0;
    int count = 0;
    while (idx < attacks.size())
    {
        curAtkT = attacks[idx][0];
        curDmg = attacks[idx][1];
        ++curT;
        ++count;
        if (curT == curAtkT)
        {
            health = Clamp(health - curDmg, 0, MaxHP);
            ++idx;
            count = 0;

            if (health <= 0) break;
        }
        else
        {
            int delta = x;
            if (count >= t)
            {
                count = 0;
                delta += y;
            }

            health = Clamp(health + delta, 0, MaxHP);
        }
    }

    answer = (health <= 0 ? -1 : health);

    return answer;
}