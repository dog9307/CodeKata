#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.resize(numbers.size(), -1);
    
    vector<int> st;
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        while (!st.empty())
        {
            if (numbers[st.back()] < numbers[i])
            {
                answer[st.back()] = numbers[i];
                st.pop_back();
            }
            else
            {
                break;
            }
        }
        st.push_back(i);
    }
    
    return answer;
}