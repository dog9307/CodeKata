#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int lux, luy;
    int rdx, rdy;
    
    lux = luy = 51;
    rdx = rdy = -1;
    
    answer.resize(4);
    for (int i = 0; i < wallpaper.size(); ++i)
    {
        int minPos = wallpaper[i].find('#');
        int maxPos = wallpaper[i].rfind('#');
        
        if (minPos != string::npos)
        {
            if (i < lux)
            {
                lux = i;
            }
            if (minPos < luy)
            {
                luy = minPos;
            }
        }
        if (maxPos != string::npos)
        {
            if (i > rdx)
            {
                rdx = i;
            }
            if (maxPos > rdy)
            {
                rdy = maxPos;
            }
        }
    }
    ++rdx;
    ++rdy;
    
    answer[0] = lux;
    answer[1] = luy;
    answer[2] = rdx;
    answer[3] = rdy;
    
    return answer;
}