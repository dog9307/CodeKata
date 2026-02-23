#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey)
    {
        int plus = 1;
        if (storey % 10 < 5)
        {
            plus = -1;
        }
        else if (storey % 10 > 5)
        {
            plus = 1;
        }
        else
        {
            int digit = storey % 100;
            digit /= 10;
            if (digit <= 4)
            {
                plus = -1;
            }
            else
            {
                plus = 1;
            }
        }
        
        while (storey % 10 != 0)
        {
            storey += plus;
            ++answer;
        }
        
        do
        {
            storey /= 10;
        } while (storey > 0 && storey % 10 == 0);
    }
    
    return answer;
}