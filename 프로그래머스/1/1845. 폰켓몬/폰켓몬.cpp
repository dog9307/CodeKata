#include <vector>

#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
            //    num count
    unordered_map<int, int> mMon;
    for(auto& n : nums)
    {
        ++mMon[n];
    }
    
    set<int> sPickedMon;
    int maxCount = nums.size() / 2;
    int currentCount = 0;
    while (currentCount < maxCount)
    {
        for (auto& mon : mMon)
        {
            if (mon.second > 0)
            {
                sPickedMon.insert(mon.first);
                --mon.second;
                ++currentCount;
                if (currentCount >= maxCount) break;
            }
        }
    }
    
    answer = sPickedMon.size();
    
    return answer;
}