#include <string>
#include <vector>

#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    int cur = 1;
    stack<int> sub;
    for (int i = 0; i < order.size(); ++i)
    {
        int prev = i;
        while (cur < order[i])
        {
            sub.push(cur);
            ++cur;
        }

        if (cur == order[i])
        {
            ++answer;
            ++cur;
            ++i;
        }

        while (!sub.empty())
        {
            if (sub.top() == order[i])
            {
                ++answer;
                sub.pop();
                ++i;
            }
            else break;
        }

        --i;
        if (prev == i + 1)
            break;
    }

    return answer;
}