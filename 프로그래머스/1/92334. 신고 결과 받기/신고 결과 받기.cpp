#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());
    
    map<string, int> mIdIdx;
    map<string, set<string>> mIdReported;
    map<string, int> reportedCount;
    
    for (int i = 0; i < id_list.size(); ++i)
    {
        mIdReported[id_list[i]] = {};
        mIdIdx[id_list[i]] = i;
    }
    
    for (int i = 0; i < report.size(); ++i)
    {
        int pos = report[i].find(' ');
        string reporter = report[i].substr(0, pos);
        string reported = report[i].substr(pos + 1);
        
        auto s = mIdReported[reported].insert(reporter);
        
        if (s.second)
            reportedCount[reported] += 1;
    }
    
    for (auto& it : reportedCount)
    {
        if (it.second >= k)
        {
            for (auto& s : mIdReported[it.first])
            {
                ++answer[mIdIdx[s]];
            }
        }
    }
    
    return answer;
}