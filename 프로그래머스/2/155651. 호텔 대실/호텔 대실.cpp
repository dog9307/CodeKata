#include <string>
#include <vector>

#include <algorithm>
#include <iostream>

using namespace std;

struct Event
{
    int time;
    bool isIn;
};

bool Compare(const Event& a, const Event& b)
{
    if (a.time != b.time)
        return a.time < b.time;
    
    return a.isIn < b.isIn;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<Event> vBooks;
    vBooks.resize(book_time.size() * 2);
    int minInTime = 25 * 60, maxOutTime = 0;
    int curIdx = 0;
    for (const auto& bt : book_time)
    {
        int ih = stoi(bt[0].substr(0, 2));
        int im = stoi(bt[0].substr(3, 2));
        int itime = ih * 60 + im;
        
        int oh = stoi(bt[1].substr(0, 2));
        int om = stoi(bt[1].substr(3, 2));
        int otime = oh * 60 + om + 10;
        
        minInTime = min(minInTime, itime);
        maxOutTime = max(maxOutTime, otime);
        
        vBooks[curIdx].time = itime;
        vBooks[curIdx].isIn = true;
        ++curIdx;
        
        vBooks[curIdx].time = otime;
        vBooks[curIdx].isIn = false;
        ++curIdx;
    }
    sort(vBooks.begin(), vBooks.end(), Compare);
    
    curIdx = 0;
    int curCount = 0;
    for (int t = minInTime; t < maxOutTime; ++t)
    {
        if (t != vBooks[curIdx].time) continue;
        
        if (vBooks[curIdx].isIn)
        {
            ++curCount;
            answer = max(answer, curCount);
        }
        else
        {
            --curCount;
        }
        
        ++curIdx;
        if (vBooks[curIdx].time == t)
        {
            --t;   
        }
    }
        
    return answer;
}