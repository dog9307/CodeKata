#include <string>
#include <vector>

#include <map>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    answer.resize(numbers.size());
    for (int i = 0; i < numbers.size(); ++i)
    {
        long long n = numbers[i];
        
        bitset<53> bi = n;
        if (bi[0] == 0)
        {
            answer[i] = n + 1;
        }
        else
        {
            int j = 0;
            while (bi[j] == 1)
            {
                ++j;
            }
            --j;
            
            answer[i] = n + pow(2, j);
        }
    }
    
    return answer;
}