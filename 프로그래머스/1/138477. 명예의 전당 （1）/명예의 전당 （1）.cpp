#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    
    for (int i = 0; i < score.size(); ++i)
    {
        if (i < k)
            temp.push_back(score[i]);
        else
        {
            for (int j = 0; j < temp.size(); ++j)
            {
                if (temp[j] < score[i])
                {
                    temp[temp.size() - 1] = score[i];
                    break;
                }
            }
        }
        
        sort(temp.rbegin(), temp.rend());
        
        answer.push_back((*(temp.end() - 1)));
    }
    
    return answer;
}