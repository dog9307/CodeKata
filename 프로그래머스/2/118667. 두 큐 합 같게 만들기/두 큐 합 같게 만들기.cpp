#include <string>
#include <vector>

#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum = 0;
    long long curQ1Sum = 0;
    queue<int> q1, q2;
    for (int i = 0; i < queue1.size(); ++i)
    {
        sum += queue1[i];
        sum += queue2[i];

        curQ1Sum += queue1[i];

        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }

    sum /= 2;
    int limit = queue1.size() * 3;
    while (!q1.empty() && !q2.empty() &&
        curQ1Sum != sum &&
        answer < limit)
    {
        queue<int> *from = nullptr, *to = nullptr;
        int multi = -1;
        if (curQ1Sum > sum)
        {
            from = &q1;
            to = &q2;
            multi = -1;
        }
        else if (curQ1Sum < sum)
        {
            from = &q2;
            to = &q1;
            multi = 1;
        }

        int temp = from->front();
        from->pop();
        curQ1Sum += temp * multi;
        to->push(temp);

        ++answer;
    }

    if (q1.empty() || q2.empty())
    {
        answer = -1;
    }
    else if (answer >= limit)
    {
        answer = -1;
    }

    return answer;
}