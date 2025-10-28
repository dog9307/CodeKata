#include <string>
#include <vector>

using namespace std;

void Calc(const vector<int>& numbers, const int& currentIdx, const int& target, int sum, int& answer)
{
    if (numbers.size() <= currentIdx)
    {
        if (sum == target)
            ++answer;
        
        return;
    }
    
    Calc(numbers, currentIdx + 1, target, sum + numbers[currentIdx], answer);
    Calc(numbers, currentIdx + 1, target, sum - numbers[currentIdx], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int currentIdx = 0;
    
    Calc(numbers, currentIdx, target, 0, answer);
    
    return answer;
}