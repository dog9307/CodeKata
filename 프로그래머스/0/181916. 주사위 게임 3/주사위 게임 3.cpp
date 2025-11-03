#include <string>
#include <vector>

#include <map>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    
    map<int, int> mCount;
    mCount[a] += 1;
    mCount[b] += 1;
    mCount[c] += 1;
    mCount[d] += 1;
    
    // 모두 같을 경우
    if (mCount.size() == 1)
    {
        return 1111 * a;
    }
    // 3 : 1 or 2 : 2
    else if (mCount.size() == 2)
    {
        // 2 : 2
        if (mCount[a] == 2)
        {
            int p = a;
            int q = (a != b ? b : (a != c ? c : d));
            
            return (p + q) * abs(p - q);
        }
        // 3 : 1
        else
        {
            int p, q;
            for (auto& m : mCount)
            {
                if (m.second == 1)
                {
                    q = m.first;
                }
                else
                {
                    p = m.first;
                }
            }
            
            return (10 * p + q) * (10 * p + q);
        }
    }
    // 2 : 1 : 1
    else if (mCount.size() == 3)
    {
        int p = 0, q = 0, r = 0;
        for (auto& m : mCount)
        {
            if (m.second == 2)
            {
                p = m.first;
            }
            else if (m.second == 1)
            {
                if (q == 0)
                {
                    q = m.first;
                }
                else
                {
                    r = m.first;
                }
            }
        }
        
        return q * r;
    }
    else if (mCount.size() == 4)
    {
        int min = a;
        min = (min > b ? b : min);
        min = (min > c ? c : min);
        min = (min > d ? d : min);
        
        return min;
    }
    
    return answer;
}