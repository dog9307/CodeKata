#include <string>
#include <vector>

#include <map>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    // sum  indexes
    map<int, vector<int>> mStu;
    for (int i = 0; i < score.size(); ++i)
    {
        mStu[score[i][0] + score[i][1]].push_back(i);
    }
    
    answer.resize(score.size());
    int count = 1;
    for (auto iter = mStu.rbegin(); iter != mStu.rend(); ++iter)
    {
        for (auto& i : iter->second)
        {
            answer[i] = count;
        }
        
        count += iter->second.size();
    }
    
    return answer;
}