#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    m['R'] = 0; // RT TR
    m['C'] = 0; // CF FC
    m['J'] = 0; // JM MJ
    m['A'] = 0; // AN NA
    
    for (int i = 0; i < survey.size(); ++i)
    {
        int score = choices[i] - 4;
        int targetIdx = 0;
        
        if (survey[i][0] == 'T' ||
            survey[i][0] == 'F' ||
            survey[i][0] == 'M' ||
            survey[i][0] == 'N')
        {
            score *= -1;
            targetIdx = 1;
        }
        
        m[survey[i][targetIdx]] += score;
    }
    
    if (m['R'] <= 0) answer += "R"; else answer += "T";
    if (m['C'] <= 0) answer += "C"; else answer += "F";
    if (m['J'] <= 0) answer += "J"; else answer += "M";
    if (m['A'] <= 0) answer += "A"; else answer += "N";
    
    return answer;
}