#include <string>
#include <vector>

#include <iostream>

using namespace std;

bool Check(const string& s)
{
    vector<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ']')
        {
            if (st.size() != 0 && st.back() == '[')
            {
                st.pop_back();
                continue;
            }
        }
        else if (s[i] == '}')
        {
            if (st.size() != 0 && st.back() == '{')
            {
                st.pop_back();
                continue;
            } 
        }
        else if (s[i] == ')')
        {
            if (st.size() != 0 && st.back() == '(')
            {
                st.pop_back();
                continue;
            }
        }
        
        st.push_back(s[i]);
    }
    
    return st.size() == 0;
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        string newStr = s.substr(i) + s.substr(0, i);
        
        if (Check(newStr))
            ++answer;
    }
    
    return answer;
}