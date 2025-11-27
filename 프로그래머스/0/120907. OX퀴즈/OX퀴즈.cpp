#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<string> Split(const string& str)
{
    vector<string> vStrs;
    
    int start = 0;
    int end = str.find(' ');
    while (start != string::npos)
    {
        string sub = str.substr(start, end - start);
        vStrs.push_back(sub);
        
        start = end + 1;
        end = str.find(' ', start + 1);
        
        if (end == string::npos) break;
    }
    string sub = str.substr(start);
    vStrs.push_back(sub);
    
    return vStrs;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    answer.resize(quiz.size());
    for (int i = 0; i < quiz.size(); ++i)
    {
        vector<string> vStrs = Split(quiz[i]);
        
        int X = stoi(vStrs[0]);
        int Y = stoi(vStrs[2]);
        
        char op = vStrs[1][0];
        
        int Z;
        if (op == '+')
            Z = X + Y;
        else if (op == '-')
            Z = X - Y;
        
        answer[i] = (Z == stoi(vStrs[4]) ? "O" : "X");
    }
    
    return answer;
}