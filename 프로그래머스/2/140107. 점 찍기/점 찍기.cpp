#include <string>
#include <vector>

#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    long long radPow = (long long)d * (long long)d;
    for (int a = 0; a * k <= d; ++a)
    {
        long long x = a * k;
        long long yMax = sqrt(radPow - (long long)(x * x));
        long long count = (yMax / k) + 1;
        
        answer += count;
    }
    
    return answer;
}