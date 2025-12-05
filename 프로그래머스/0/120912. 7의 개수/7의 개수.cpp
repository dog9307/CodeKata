#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for (auto& n : array)
    {
        string str = to_string(n);
        answer += count(str.begin(), str.end(), '7');
    }
    
    return answer;
}