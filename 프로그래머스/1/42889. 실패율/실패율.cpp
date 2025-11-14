#include <string>
#include <vector>

#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N, 0);
    
    sort(stages.rbegin(), stages.rend());
    
    // stage fail
    map<int, float> mFail;
    for (int i = 1; i <= N; ++i)
    {
        mFail[i] = 0;
    }
    
    int reachCount = 0;
    for (int i = 0; i < stages.size();)
    {
        int targetStage = stages[i];
        int targetStageCount = 0;
        while (stages[i] == targetStage)
        {
            ++i;
            ++reachCount;
            ++targetStageCount;
        }
        
        if (targetStage == N + 1) continue;
        
        float fail = ((float)targetStageCount / (float)reachCount * 100.0f);
        mFail[targetStage] = fail;
    }
    
    // fail  stages
    map<float, vector<int>> mReverse;
    for (auto& f : mFail)
    {
        mReverse[f.second].push_back(f.first);
    }
    
    int index = 0;
    for (auto iter = mReverse.rbegin(); iter != mReverse.rend(); ++iter)
    {
        for (auto& r : iter->second)
        {
            answer[index++] = r;
        } 
    }
    
    return answer;
}