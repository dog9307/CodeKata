#include <string>
#include <vector>

#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    cout << new_id << endl;
    
    transform(new_id.begin(), new_id.end(), new_id.begin(), [](char c){return tolower(c);});
    
    for (int i = 0; i < new_id.size();)
    {
        if (('a' <= new_id[i] && new_id[i] <= 'z') ||
            ('0' <= new_id[i] && new_id[i] <= '9') ||
           new_id[i] == '-' ||
           new_id[i] == '_' ||
           new_id[i] == '.')
        {
            ++i;
            continue;
        }
        
        new_id.erase(i, 1);
    }
    
    int pos = new_id.find("..", pos);
    while (pos != string::npos)
    {
        new_id.replace(pos, 2, ".");
        pos = new_id.find("..", pos);
    }
    
    if (new_id[0] == '.')
        new_id.erase(0, 1);
    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.size() - 1, 1);
    
    if (new_id.size() <= 0)
        new_id += "a";
    if (new_id.size() >= 16)
    {
        new_id.erase(15);
        
        if (new_id[0] == '.')
            new_id.erase(0, 1);
        if (new_id[new_id.size() - 1] == '.')
            new_id.erase(new_id.size() - 1, 1);
    }
    
    while (new_id.size() < 3)
    {
        new_id += new_id[new_id.size() - 1];
    }
    
    answer = new_id;
    
    return answer;
}