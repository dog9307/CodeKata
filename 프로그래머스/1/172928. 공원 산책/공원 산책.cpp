#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    // y, x
    vector<int> answer;
    
    answer.resize(2);
    for (int i = 0; i < park.size(); ++i)
    {
        int pos = park[i].find("S");
        if (pos != string::npos)
        {
            answer[0] = i;
            answer[1] = pos;
            break;
        }
    }
    
    int w = park[0].size();
    int h = park.size();
    for (int i = 0; i < routes.size(); ++i)
    {
        char op = routes[i][0];
        int num = stoi(routes[i].substr(2));
        int targetIdx = 0;
        int limit = h;
        int mul = 1;
        if (op == 'E' || op == 'W')
        {
            targetIdx = 1;
            limit = w;
        }
        if (op == 'N' || op == 'W')
        {
            mul = -1;
        }
        
        int prev = answer[targetIdx];
        bool isCanMove = true;
        for (int j = 0; j < num; ++j)
        {
            answer[targetIdx] = answer[targetIdx] + mul;
            if (answer[targetIdx] >= limit || answer[targetIdx] < 0)
            {
                isCanMove = false;
                break;
            }
            if (park[answer[0]][answer[1]] == 'X')
            {
                isCanMove = false;
                break;
            }
        }
        
        if (!isCanMove)
            answer[targetIdx] = prev;
    }
    
    return answer;
}