#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string digits[10] = 
    {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    
    for (int i = 0; i < 10; ++i)
    {
        size_t pos = 0;
        while ((pos = s.find(digits[i], pos)) != string::npos)
        {
            s.replace(pos, digits[i].size(), to_string(i));
        }
    }
    
    answer = stoi(s);
    
    return answer;
}