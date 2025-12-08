#include <string>
#include <vector>

#include <map>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
                    //id pw
    map<string, string> mDB;
    for (auto& u : db)
    {
        mDB[u[0]] = u[1];
    }
    
    auto iter = mDB.find(id_pw[0]);
    if (iter != mDB.end())
    {
        if (iter->second == id_pw[1])
        {
            answer = "login";
        }
        else
        {
            answer = "wrong pw";
        }
    }
    else
    {
        answer = "fail";
    }
    
    return answer;
}