#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    answer.resize(targets.size());
    for (int i = 0; i < targets.size(); ++i)
    {
        for (auto& c : targets[i])
        {
            int minPos = 101;
            for (auto& s : keymap)
            {
                int pos = s.find(c);
                if (minPos > pos && pos >= 0)
                {
                    minPos = pos;
                    if (minPos == 0)
                        break;
                }
            }

            if (minPos >= 101)
            {
                answer[i] = -1;
                break;
            }

            answer[i] += minPos + 1;
        }
    }

    return answer;
}
