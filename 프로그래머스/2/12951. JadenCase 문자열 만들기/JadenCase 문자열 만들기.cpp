#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string TransformStr(const string& origin, int startIndex, int length)
{
    string sub = origin.substr(startIndex, length);
        
    if (!isdigit(sub[0]))
        sub[0] = toupper(sub[0]);

    if (sub.size() >= 2)
    {
        transform(sub.begin() + 1, sub.end(), sub.begin() + 1,
                 [](unsigned char ch) { return tolower(ch); });
    }
    
    return sub;
}

string solution(string s) {
    string answer = "";
    
    int pos = s.find(' ');
    int startIndex = 0;
    string sub = "";
    while (pos != string::npos)
    {
        answer += TransformStr(s, startIndex, pos - startIndex) + " ";
        
        startIndex = pos + 1;
        pos = s.find(' ', startIndex);
    }
    
    answer += TransformStr(s, startIndex, pos - startIndex);
    
    return answer;
}