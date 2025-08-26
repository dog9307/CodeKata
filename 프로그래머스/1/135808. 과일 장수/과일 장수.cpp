#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    
    while (score.size() >= m)
    {
        int minScore = score[score.size() - 1];
        score.pop_back();
        for (int i = 1; i < m; ++i)
        {
            int temp = score[score.size() - 1];
            score.pop_back();
            if (minScore > temp)
            {
                minScore = temp;
            }
        }
        
        answer += minScore * m;
    }
    
    
    return answer;
}