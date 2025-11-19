#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;

    int start = 0;
    int end = myString.find("x");
    while (end != string::npos)
    {
        string sub = myString.substr(start, end - start);
        answer.push_back(sub.size());

        start = end + 1;
        while (myString[start] == 'x')
        {
            ++start;
            answer.push_back(0);
        }
        end = myString.find("x", start + 1);
    }

    string sub = myString.substr(start);
    answer.push_back(sub.size());


    return answer;
}