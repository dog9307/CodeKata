#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, -1);

    int minLength = 1000001;
    int left = 0;
    int right = 0;
    int sum = sequence[left];
    while (right < sequence.size() && left < sequence.size())
    {
        if (sum < k)
        {
            ++right;
            if (right >= sequence.size()) break;

            sum += sequence[right];
        }
        else if (sum > k)
        {
            sum -= sequence[left];
            ++left;
        }
        else
        {
            if (right - left + 1 < minLength)
            {
                minLength = right - left + 1;
                answer[0] = left;
                answer[1] = right;
            }

            sum -= sequence[left];
            ++left;
        }
    }

    return answer;
}