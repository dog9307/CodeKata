#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> nums;
    int pos = s.find(' ');
    int startIndex = 0;
    while (pos != string::npos)
    {
        nums.push_back(stoi(s.substr(startIndex, pos - startIndex)));
        startIndex = pos + 1;
        pos = s.find(" ", startIndex);
    }
    nums.push_back(stoi(s.substr(startIndex)));
    
    
    auto minIt = min_element(nums.begin(), nums.end());
    auto maxIt = max_element(nums.begin(), nums.end());
    
    answer += to_string(*minIt) + " " + to_string(*maxIt);
    
    return answer;
}