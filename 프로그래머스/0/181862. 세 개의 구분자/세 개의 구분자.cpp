#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;

    int s = 0;
    int e = s + 1;

    while (s < myStr.size())
    {
        while (myStr[s] == 'a' ||
            myStr[s] == 'b' ||
            myStr[s] == 'c')
            ++s;

        int ai = myStr.find('a', s + 1);
        int bi = myStr.find('b', s + 1);
        int ci = myStr.find('c', s + 1);

        if (ai != string::npos &&
            bi != string::npos &&
            ci != string::npos)
            e = (ai < bi && ai < ci ? ai : (bi < ci ? bi : ci));
        else
        {
            if (ai != string::npos &&
                bi != string::npos)
            {
                e = (ai < bi ? ai : bi);
            }
            else if (bi != string::npos &&
                     ci != string::npos)
            {
                e = (bi < ci ? bi : ci);
            }
            else if (ai != string::npos &&
                     ci != string::npos)
            {
                e = (ai < ci ? ai : ci);
            }
            else if (ai != string::npos)
            {
                e = ai;
            }
            else if (bi != string::npos)
            {
                e = bi;
            }
            else if (ci != string::npos)
            {
                e = ci;
            }
            else
                e = myStr.size();
        }

        string sub = myStr.substr(s, e - s);

        if (sub.size() >= 1)
            answer.push_back(sub);

        s = e;
    }


    if (answer.size() <= 0)
        answer.push_back("EMPTY");

    return answer;
}