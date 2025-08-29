#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string toBinary(int num)
{
    string bi = "";
    while (num)
    {
        bi += to_string(num % 2);
        num /= 2;
    }
    
    reverse(bi.begin(), bi.end());
    return bi;
}

vector<int> solution(string s) {
    vector<int> answer;
    answer.resize(2);
    
    int biCount = 0;
    int removeZeroCount = 0;
    while (s != "1")
    {
        sort(s.rbegin(), s.rend());
        
        int pos = s.find("0");
        
        if (pos != string::npos)
            removeZeroCount += s.size() - pos;
        
        s = s.substr(0, pos);
        
        s = toBinary(s.size());
        
        ++biCount;
    }
    
    answer[0] = biCount;
    answer[1] = removeZeroCount;
    
    return answer;
}