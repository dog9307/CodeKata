#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for (int num = i; num <= j; ++num)
    {
        string str = to_string(num);
        answer += count(str.begin(), str.end(), static_cast<char>(k + '0'));
    }
    
    return answer;
}