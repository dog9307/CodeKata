#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    while (X.size() != 0 && Y.size() != 0)
    {
        if (X[X.size() - 1] == Y[Y.size() - 1])
        {
            answer += X[X.size() - 1];
            
            X.pop_back();
            Y.pop_back();
        }
        else
        {
            if (X[X.size() - 1] > Y[Y.size() - 1])
                X.pop_back();
            else
                Y.pop_back();
        }
    }
    
    if (answer.size() == 0)
        answer += "-1";
    else if (answer[0] == '0')
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer;
}