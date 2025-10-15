#include <string>
#include <vector>

#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.rbegin(), citations.rend());
    
    if (citations[citations.size() - 1] >= citations.size())
        return citations.size();
    
    for (int i = 0; i < citations.size(); ++i)
    {
        if (citations[i] <= i)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}