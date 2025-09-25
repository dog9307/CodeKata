#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    answer.resize(2);
    
    for (int i = 1; i <= yellow; ++i)
    {
        if (yellow % i != 0) continue;
        
        int yH = i;
        int yW = yellow / i;
        
        if (yW * 2 + yH * 2 + 4 == brown)
        {
            answer[0] = yW + 2;
            answer[1] = yH + 2;
            break;
        }
    }
    
    return answer;
}