#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a)
    {
        int sum = (n / a) * b;
        
        answer += sum;
        
        n = (n - (n / a) * a) + sum;
    }
    
    return answer;
}