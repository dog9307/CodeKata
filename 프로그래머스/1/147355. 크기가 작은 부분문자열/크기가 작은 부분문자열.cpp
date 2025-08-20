#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int startIndex = 0;
    while (startIndex + p.size() <= t.size())
    {
        string sub = t.substr(startIndex, p.size());
        long long num1 = stol(sub);
        long long num2 = stol(p);
        
        if (num1 <= num2)
            answer++;
        
        startIndex++;
    }
    
    return answer;
}