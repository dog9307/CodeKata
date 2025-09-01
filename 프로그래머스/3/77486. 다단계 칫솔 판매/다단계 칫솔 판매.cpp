#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    
    // enroll : referral
    unordered_map<string, string> parent;
    for (int i = 0 ; i < enroll.size(); ++i)
    {
        parent[enroll[i]] = referral[i];
    }
    
    // total
    unordered_map<string, int> total;
    for (auto& e : enroll)
    {
        total[e] = 0;
    }
    
    for (int i = 0; i < seller.size(); ++i)
    {
        string currentSeller = seller[i];
        int benefit = amount[i] * 100;
        
        while (currentSeller != "-")
        {
            int duty = benefit * 0.1f;
            if (duty < 1)
            {
                total[currentSeller] += benefit;                
                break;
            }
            else
            {
                total[currentSeller] += (benefit - duty);
                
                benefit = duty;
                currentSeller = parent[currentSeller];
            }
        }
    }
    
    for (int i = 0; i < answer.size(); ++i)
    {
        answer[i] = total[enroll[i]];
    }
    
    return answer;
}
