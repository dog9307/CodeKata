#include <string>
#include <vector>
#include <map>

using namespace std;

struct Day
{
    int y;
    int m;
    int d;
};

void ParsingDay(const string& day, Day& _d)
{
    _d.y = stoi(day.substr(0, 4));
    _d.m = stoi(day.substr(5, 2));
    _d.d = stoi(day.substr(8, 2));
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    Day td;
    ParsingDay(today, td);
    
    map<char, int> mTerms;
    for (int i = 0; i < terms.size(); ++i)
    {
        mTerms[terms[i][0]] = stoi(terms[i].substr(2, terms[i].size() - 2));
    }
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        char p = privacies[i][privacies[i].size() - 1];
        Day d;
        ParsingDay(privacies[i], d);
        
        bool isDestroy = false;
        
        d.m += mTerms[p];
        while (d.m > 12)
        {
            d.m -= 12;
            ++d.y;
        }
        
        if (td.y > d.y)
            isDestroy = true;
        else if (td.y >= d.y &&
                 td.m > d.m)
            isDestroy = true;
        else if (td.y >= d.y &&
                 td.m >= d.m &&
                 td.d >= d.d)
            isDestroy = true;
        
        if (isDestroy)
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}