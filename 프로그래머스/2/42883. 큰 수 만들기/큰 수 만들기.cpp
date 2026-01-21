#include <string>
#include <vector>

#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    vector<char> vNum;
    for (int i = number.size() - 1; i >= 0; --i)
    {
        if (vNum.empty())
        {
            vNum.push_back(number[i]);
        }
        else
        {
            if (vNum.size() < number.size() - k)
            {
                vNum.push_back(number[i]);
            }
            else
            {
                char target = number[i];
                int curIdx = vNum.size() - 1;
                while (curIdx >= 0 && vNum[curIdx] <= target)
                {
                    char temp = vNum[curIdx];
                    vNum[curIdx] = target;
                    target = temp;

                    --curIdx;
                }
            }
        }
    }

    for (int i = vNum.size() - 1; i >= 0; --i)
    {
        answer += vNum[i];
    }

    return answer;
}