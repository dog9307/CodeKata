#include <string>
#include <vector>

#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    answer.resize(my_string.size());
    for (int length = 1; length <= my_string.size(); ++length)
    {
        string sub = my_string.substr(my_string.size() - 1 - (length - 1), length);
        answer[length - 1] = sub;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}