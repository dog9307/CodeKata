#include <string>
#include <vector>

#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    set<int> sums;
    for (int length = 1; length <= elements.size(); ++length)
    {
        for (int startIdx = 0; startIdx < elements.size(); ++startIdx)
        {
            int sum = 0;
            for (int i = 0; i < length; ++i)
            {
                sum += elements[(startIdx + i) % elements.size()];
            }
            sums.insert(sum);
        }
    }
    answer = sums.size();
    
    return answer;
}