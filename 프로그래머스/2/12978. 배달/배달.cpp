#include <iostream>
#include <vector>

#include <queue>

using namespace std;

vector<pair<int, int>> adj[2001];

int dist[2001];

void CalcTime()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, 1 });
    dist[1] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto& next : adj[cur])
        {
            int nextNode = next.first;
            int nextCost = cost + next.second;

            if (nextCost < dist[nextNode])
            {
                dist[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    for (int i = 1; i <= N; ++i)
    {
        dist[i] = 2147483647;
    }

    for (const auto& r : road)
    {
        adj[r[0]].push_back({ r[1], r[2] });
        adj[r[1]].push_back({ r[0], r[2] });
    }

    CalcTime();

    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] <= K)
        {
            ++answer;
        }
    }

    return answer;
}