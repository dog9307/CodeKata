#include <string>
#include <vector>

#include <map>

#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, vector<string>> mClothes;
    vector<int> vCount;
    for (auto& c : clothes)
    {
        mClothes[c[1]].push_back(c[0]);
    }
    for (auto& v : mClothes)
    {
        vCount.push_back(v.second.size());
    }
    
    if (vCount.size() == 1)
    {
        answer = vCount[0];   
    }
    else
    {
        int mul = 1;
        for (auto& c : vCount)
        {
            mul *= (c + 1);
        }
        answer = mul - 1;
    }
    
    return answer;
}