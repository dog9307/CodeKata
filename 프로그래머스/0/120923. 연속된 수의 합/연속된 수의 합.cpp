#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int start = -(num / 2);
    int end = start + num - 1;
    
    int n = end - (start - 1);
    int sum = (n * (n + 1)) / 2 + n * (end - n);
    
    while (sum != total)
    {
        ++start;
        end = start + num - 1;
    
        n = end - (start - 1);
        sum = (n * (n + 1)) / 2 + n * (end - n);
    }
    
    answer.resize(num);
    for (int i = start; i <= end; ++i)
        answer[i - start] = i;
    
    return answer;
}