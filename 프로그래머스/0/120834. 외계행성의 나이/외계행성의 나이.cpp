#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    string ageStr = to_string(age);
    
    for (auto& c : ageStr)
    {
        answer += c + ('a' - '0');
    }
    
    return answer;
}