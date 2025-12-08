#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for (auto& s : s1)
    {
        answer += count(s2.begin(), s2.end(), s);
    }
    
    return answer;
}