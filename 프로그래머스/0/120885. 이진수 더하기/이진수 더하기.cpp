#include <string>
#include <vector>

#include <iostream>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    
    while (bin1.size() < bin2.size())
    {
        bin1 = "0" + bin1;
    }
    
    while (bin2.size() < bin1.size())
    {
        bin2 = "0" + bin2;
    }
    
    for (int i = 0; i < bin1.size(); ++i)
    {
        answer += bin1[i] + bin2[i] - '0';
    }
    
    int pos = answer.find("2");
    while (pos != string::npos)
    {
        answer[pos] = '0';
        
        if (pos == 0)
        {
            answer = "1" + answer;
        }
        else
        {
            ++answer[pos - 1];
        }
        
        pos = answer.find("2");
    }
    
    
    return answer;
}