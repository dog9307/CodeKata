#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for (int i = 0; i < sizes.size(); ++i)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            int swp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = swp;
        }
    }
    
    int maxW = sizes[0][0];
    int maxH = sizes[0][1];
    for (int i = 1; i < sizes.size(); ++i)
    {
        maxW = max(maxW, sizes[i][0]);
        maxH = max(maxH, sizes[i][1]);
    }
    answer = maxW * maxH;
    
    return answer;
}