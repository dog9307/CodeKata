#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    // 0번과 1번
    vector<long long> mem = {1, 1};
    
    // 2번부터
    for (int i = 2; i <= n; ++i)
    {
        mem.emplace_back((mem[i - 1] + mem[i - 2]) % 1234567);
    }
    answer = mem.back();
    
    return answer;
}