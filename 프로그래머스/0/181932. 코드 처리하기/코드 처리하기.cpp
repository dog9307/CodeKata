#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    
    bool mode = false;
    
    for (int i = 0; i < code.size(); ++i)
    {
        if (code[i] == '1')
        {
            mode = !mode;
            continue;
        }
        
        if (i % 2 == (int)(mode))
            answer += code[i];
    }
    
    if (answer.size() <= 0)
        answer = "EMPTY";
    
    return answer;
}