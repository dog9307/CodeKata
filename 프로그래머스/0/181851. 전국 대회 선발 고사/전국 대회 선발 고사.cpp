#include <string>
#include <vector>

#include <map>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    // rank index
    map<int, int> mRank;
    for (int i = 0; i < rank.size(); ++i)
    {
        if (attendance[i])
            mRank[rank[i]] = i;
    }
    
    auto iter = mRank.begin();
    int a = iter->second;
    ++iter;
    int b = iter->second;
    ++iter;
    int c = iter->second;
    
    answer = 10000 * a + 100 * b + c;
    
    return answer;
}