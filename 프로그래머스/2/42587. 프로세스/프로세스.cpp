#include <string>
#include <vector>

#include <queue>
#include <algorithm>

using namespace std;

struct P
{
    int priority;
    int idx;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<P> pQ;
    for (int i = 0; i < priorities.size(); ++i)
    {
        P p = { priorities[i], i };
        pQ.push(p);
    }

    while (pQ.size() > 0 && priorities.size() > 0)
    {
        auto maxP = max_element(priorities.begin(), priorities.end());

        P cur = pQ.front();
        pQ.pop();

        while (cur.priority != *maxP)
        {
            pQ.push(cur);

            cur = pQ.front();
            pQ.pop();
        }

        ++answer;

        if (location == cur.idx) return answer;

        priorities.erase(maxP);
    }

    return answer;
}