#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer;
    answer.resize(end_num - start_num + 1);
    int cur = start_num;
    for (auto& n : answer)
    {
        n = start_num++;
    }
    
    return answer;
}