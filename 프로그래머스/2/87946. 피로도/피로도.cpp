#include <string>
#include <vector>

#include <algorithm>

using namespace std;

vector<bool> visited;

void DFS(const vector<vector<int>>& dungeons, int count, int k, vector<int>& results)
{
    results.push_back(count);
    
    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (visited[i]) continue;
        
        if (k >= dungeons[i][0])
        {
            visited[i] = true;
            
            DFS(dungeons, count + 1, k - dungeons[i][1], results);
            
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    vector<int> results;
    visited.resize(dungeons.size());
    for (int j = 0; j < visited.size(); ++j)
    {
        visited[j] = false;
    }
    
    DFS(dungeons, 0, k, results);
    
    answer = *(max_element(results.begin(), results.end()));
    
    return answer;
}