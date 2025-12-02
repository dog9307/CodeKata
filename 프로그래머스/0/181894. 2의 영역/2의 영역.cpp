#include <string>
#include <vector>

#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    auto start = find(arr.begin(), arr.end(), 2);
    if (start == arr.end())
    {
        answer.push_back(-1);
    }
    else
    {
        auto end = find(arr.rbegin(), arr.rend(), 2);
        
        int startIdx = start - arr.begin();
        int endIdx = (arr.size() - 1) - (end - arr.rbegin());
        
        for (int i = startIdx; i <= endIdx; ++i)
        {
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}