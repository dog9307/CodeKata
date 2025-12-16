#include <string>
#include <vector>

#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    vector<int> vCount(1000, 0);
    
    for (auto& n : array)
    {
        ++vCount[n];
    }
    
    int maxC = -1;
    int maxV = -1;
    for (auto& n : array)
    {
        if (vCount[n] > maxC)
        {
            maxC = vCount[n];
            maxV = n;
        }
    }
    
    for (auto& n : array)
    {
        if (vCount[n] == maxC)
        {
            if (n != maxV)
            {
                return -1;
            }
        }
    }
    
    answer = maxV;
    
    return answer;
}