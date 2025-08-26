#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        for (int j = i + 1; j < nums.size() - 1; ++j)
        {
            for (int k = j + 1; k < nums.size(); ++k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                bool isPrime = true;
                for (int start = 2; start < sum; ++start)
                {
                    if (sum % start == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
                
                if (isPrime)
                    answer++;
            }
        }
    }

    return answer;
}