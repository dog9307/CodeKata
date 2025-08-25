#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    reverse(cards1.begin(), cards1.end());
    reverse(cards2.begin(), cards2.end());
    reverse(goal.begin(), goal.end());
    
    while (goal.size() > 0)
    {
        if (cards1.size() >= 1)
        {
            if (cards1[cards1.size() - 1] == goal[goal.size() - 1])
            {
                goal.pop_back();
                cards1.pop_back();
                continue;
            }
        }
        if (cards2.size() >= 1)
        {
            if (cards2[cards2.size() - 1] == goal[goal.size() - 1])
            {
                goal.pop_back();
                cards2.pop_back();
                continue;
            }
        }
        
        return "No";
    }
    
    return "Yes";
}