#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int index1 = 0;
    int index2 = 0;
    int goalIndex = 0;
    
    while (goalIndex < goal.size())
    {
        if (cards1[index1] == goal[goalIndex])
        {
            ++index1;
            ++goalIndex;
            continue;
        }
        if (cards2[index2] == goal[goalIndex])
        {
            ++index2;
            ++goalIndex;
            continue;
        }
        
        return "No";
    }
    
    return "Yes";
}