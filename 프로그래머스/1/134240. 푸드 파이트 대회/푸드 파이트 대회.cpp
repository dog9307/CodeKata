#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for (int i = 1; i < food.size(); ++i)
    {
        if (food[i] <= 1) continue;
        
        answer.append(food[i] / 2, (char)(i + '0'));
    }
    string temp = answer;
    reverse(temp.begin(), temp.end());
    
    answer += "0" + temp;
    
    return answer;
}
