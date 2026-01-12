#include <string>
#include <vector>

#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    map<int, int> leftSide;
    map<int, int> rightSide;
    
    for (auto& t : topping)
    {
        ++rightSide[t];
    }
    
    for (auto& t : topping)
    {
        --rightSide[t];
        ++leftSide[t];
        
        if (rightSide[t] <= 0)
        {
            rightSide.erase(t);
        }
        
        if (leftSide.size() == rightSide.size())
        {
            ++answer;
        }
    }

    return answer;
}