#include <string>
#include <vector>

#include <math.h>
#include <algorithm>

#include <set>

using namespace std;

bool IsPrime(int num)
{
    if (num <= 1) return false;
    
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int solution(string numbers) {
    
    set<int> sNums;
    
    sort(numbers.begin(), numbers.end());
    
     do
     {
         for (int i = 1; i <= numbers.size(); ++i)
         {
             string numStr = numbers.substr(0, i);
             int temp = stoi(numStr);
             if (IsPrime(temp))
             {
                 sNums.insert(temp);
             }
         }
     } while (next_permutation(numbers.begin(), numbers.end()));
    
    return sNums.size();
}