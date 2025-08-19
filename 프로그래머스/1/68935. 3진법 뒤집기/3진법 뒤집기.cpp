#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string third = "";
    while (n)
    {
        third += to_string(n % 3);
         n /= 3;
    }
    
    for (int i = 0; i < third.size(); ++i)
    {
        answer += ((int)(third[i] - '0') * pow(3, third.size() - 1 - i));
    }
    
    return answer;
}