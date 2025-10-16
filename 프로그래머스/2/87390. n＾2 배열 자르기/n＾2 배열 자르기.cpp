#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    answer.resize(right - left + 1);
    int idx = 0;
    for (long long i = left; i <= right; ++i)
    {
        int row = i / n;
        int col = i % n;
        
        int num = col;
        
        answer[idx] = (num < row ? row : num) + 1;
        ++idx;
    }
    
    return answer;
}