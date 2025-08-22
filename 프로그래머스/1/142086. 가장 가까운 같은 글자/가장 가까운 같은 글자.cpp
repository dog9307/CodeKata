#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    answer.push_back(-1);
    for (int i = 1; i < s.size(); ++i)
    {
        size_t pos = s.find(s[i]);
        size_t prevPos = i + 1;

        while (pos != string::npos && pos < i)
        {
            prevPos = pos;
            pos = s.find(s[i], pos + 1);
        }

        answer.push_back(i - prevPos);
    }
    
    return answer;
}