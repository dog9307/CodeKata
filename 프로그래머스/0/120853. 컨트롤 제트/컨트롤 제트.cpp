#include <string>
#include <vector>

#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    vector<string> vStr;
    int start = 0;
    int end = s.find(" ");
    while (end != string::npos)
    {
        vStr.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(" ", start);
    }
    vStr.push_back(s.substr(start));
    
    stack<string> vSt;
    for (auto& v : vStr)
    {
        if (v == "Z")
        {
            answer -= stoi(vSt.top());
            vSt.pop();
        }
        else
        {
            answer += stoi(v);
            vSt.push(v);
        }
    }
    
    return answer;
}