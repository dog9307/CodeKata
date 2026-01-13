#include <string>
#include <vector>

#include <algorithm>

using namespace std;

vector<int> dp(1000001, 1000001);

int solution(int x, int y, int n) {
    int answer = 0;
    
    dp[x] = 0;
    for (int i = x; i < y + 1; ++i)
    {
        if (dp[i] == 1000001) continue;
                
        int idx;
        
        idx = i + n;
        if (idx <= y)
        {
            dp[idx] = min(dp[idx], dp[i] + 1);
        }
        
        idx = i * 2;
        if (idx <= y)
        {
            dp[idx] = min(dp[idx], dp[i] + 1);
        }
        
        idx = i * 3;
        if (idx <= y)
        {
            dp[idx] = min(dp[idx], dp[i] + 1);
        }
    }
    
    if (dp[y] == 1000001)
    {
        answer = -1;
    }
    else
    {
        answer = dp[y];
    }
        
    return answer;
}