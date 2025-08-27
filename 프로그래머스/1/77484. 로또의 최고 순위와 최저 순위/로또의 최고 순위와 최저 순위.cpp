#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int count = 0;
    int zeroCount = 0;
    for (int i = 0; i < lottos.size(); ++i)
    {
        if (lottos[i] == 0)
            zeroCount++;
        else
        {
            for (int j = 0; j < win_nums.size(); ++j)
            {
                if (lottos[i] == win_nums[j])
                {
                    count++;
                    break;
                }
            }
        }
    }
    
    answer.resize(2);
    answer[0] = (count + zeroCount <= 0 ? 6 : 7 - (count + zeroCount));
    answer[1] = (count <= 0 ? 6 : 7 - count);
    
    return answer;
}