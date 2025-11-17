#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    int startIdx = 0;
    int endIdx = arr.size() - 1;
    
    for (int i = 0; i < query.size(); ++i)
    {
        if (i % 2 == 0)
        {
            endIdx = startIdx + query[i];
        }
        else
        {
            startIdx += query[i];
        }
    }
    
    if (endIdx >= startIdx)
    {
        answer.resize(endIdx - startIdx + 1);
        for (int i = 0; i < answer.size(); ++i)
        {
            answer[i] = arr[i + startIdx];
        }
    }
    
    return answer;
}