#include <string>
#include <vector>

#include <algorithm>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int n, d;
    d = denom1 * denom2;
    n = numer1 * denom2 + numer2 * denom1;
    
    int g = __gcd(d, n);
    d /= g;
    n /= g;
    
    answer.resize(2);
    answer[0] = n;
    answer[1] = d;
    
    return answer;
}