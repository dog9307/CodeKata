#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> mT;
    for (int i = 0; i < tangerine.size(); ++i)
    {
        mT[tangerine[i]] += 1;
    }
    
    map<int, vector<int>> mCount;
    for (auto& m : mT)
    {
        mCount[m.second].push_back(m.first);
    }
    
    int count = 0;
    auto mIter = mCount.rbegin();
    while (mIter != mCount.rend())
    {
        for (int i = 0; i < mIter->second.size() && count < k; ++i)
        {
            count += mIter->first;
            ++answer;
        }
        
        if (count >= k) break;
        
        ++mIter;
    }
    
    return answer;
}