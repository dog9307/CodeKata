#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    answer.resize(2);
    
    int maxAbsX = board[0] / 2;
    int maxAbsY = board[1] / 2;

    int x = 0;
    int y = 0;
    for (auto& k : keyinput)
    {
        if (k == "up")
        {
            y = (y + 1 > maxAbsY ? maxAbsY : y + 1);
        }
        else if (k == "down")
        {
            y = (y - 1 < -maxAbsY ? -maxAbsY : y - 1);
        }
        else if (k == "left")
        {
            x = (x - 1 < -maxAbsX ? -maxAbsX : x - 1);
        }
        else if (k == "right")
        {
            x = (x + 1 > maxAbsX ? maxAbsX : x + 1);
        }
    }
    
    answer[0] = x;
    answer[1] = y;
    
    return answer;
}