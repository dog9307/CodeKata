#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = 0;
    
    auto iter = find(arr.begin() + idx, arr.end(), 1);
    
    int targetIdx = (iter - arr.begin());
    answer = targetIdx >= arr.size() ? -1 : targetIdx;
    
    return answer;
}