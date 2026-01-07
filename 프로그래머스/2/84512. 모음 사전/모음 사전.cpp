#include <string>
#include <vector>

#include <unordered_map>

using namespace std;

int solution(string word) {
    int answer = 0;

    unordered_map<int, char> mWord;
    mWord[0] = 'A';
    mWord[1] = 'E';
    mWord[2] = 'I';
    mWord[3] = 'O';
    mWord[4] = 'U';

    string cur = "";
    int digit[5] = { -1, -1, -1, -1, -1 };
    while (cur != word)
    {
        if (cur.size() < 5)
        {
            ++digit[cur.size()];
            if (digit[cur.size()] <= 4)
            {
                cur += mWord[digit[cur.size()]];
                ++answer;
            }
            else
            {
                digit[cur.size()] = 0;
                cur.erase(cur.size(), 1);
            }
        }
        else
        {
            ++digit[4];
            if (digit[4] <= 4)
            {
                cur[4] = mWord[digit[4]];
                ++answer;
            }
            else
            {
                if (cur == "EUUUU")
                {
                    int a = 0;
                    int b = 0;
                }
                for (int i = 4; i >= 0; --i)
                {
                    if (digit[i] > 4)
                    {
                        digit[i] = -1;
                        cur.erase(i, 1);
                        ++digit[i - 1];
                        cur[i - 1] = mWord[digit[i - 1]];
                    }
                    else
                    {
                        ++answer;
                        break;
                    }
                }
            }
        }
    }

    return answer;
}