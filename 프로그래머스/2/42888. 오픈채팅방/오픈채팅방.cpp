#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<char, string>> commands;
    map<string, string> userMap;
    
    for (int i = 0; i < record.size(); ++i)
    {
        stringstream ss(record[i]);
        string command;
        string uid;
        string id;
        
        ss >> command >> uid >> id;
        
        if (command[0] == 'E')
        {
            userMap[uid] = id;
            
            commands.push_back(make_pair('E', uid));
        }
        else if (command[0] == 'L')
        {
            commands.push_back(make_pair('L', uid));
        }
        else if (command[0] == 'C')
        {
            userMap[uid] = id;
        }
    }
    
    for (auto& c : commands)
    {
        if (c.first == 'E')
        {
            answer.push_back(userMap[c.second] + "님이 들어왔습니다.");
        }
        else if (c.first == 'L')
        {
            answer.push_back(userMap[c.second] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}