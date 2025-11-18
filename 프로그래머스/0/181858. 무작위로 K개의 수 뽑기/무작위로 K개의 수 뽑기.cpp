#include <string>
#include <vector>

#include <set>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer(k, -1);
    
    set<int> dup;
    answer[0] = arr[0];
    dup.insert(arr[0]);
    int currentIdx = 0;
    for (int i = 1; i < arr.size() && currentIdx < k; ++i)
    {
        if (dup.find(arr[i]) != dup.end()) continue;
        
        if (arr[i] != answer[currentIdx])
        {
            ++currentIdx;
            if (currentIdx >= k) break;
            
            answer[currentIdx] = arr[i];
            dup.insert(arr[i]);
        }
    }
    
    return answer;
}