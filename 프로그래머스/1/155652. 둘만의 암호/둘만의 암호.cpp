#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        for (int j = 0; j < index; ++j)
        {
            c -= 'a';
            c = (c + 1) % 26;
            c += 'a';
            
            int pos = skip.find(c);
            while (pos != string::npos)
            {
                c -= 'a';
                c = (c + 1) % 26;
                c += 'a';
                
                pos = skip.find(c);
            }
        }
        
        answer += c;
    }
    
    return answer;
}