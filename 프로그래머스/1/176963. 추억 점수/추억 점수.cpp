#include <string>
#include <vector>

#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map<string, int> mScore;
    for (int i = 0; i < name.size(); ++i)
    {
        mScore[name[i]] = yearning[i];
    }
    
    answer.resize(photo.size());
    for (int i = 0; i < photo.size(); ++i)
    {
        int score = 0;
        for (auto& p : photo[i])
        {
            score += mScore[p];
        }
        answer[i] = score;
    }
    
    return answer;
}