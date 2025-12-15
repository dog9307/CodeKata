#include <string>
#include <vector>

#include <unordered_map>

using namespace std;

string solution(string letter) {
    string answer = "";
    
    unordered_map<string, char> mMorse;
    mMorse[".-"]    = 'a';
    mMorse["-..."]  = 'b';
    mMorse["-.-."]  = 'c';
    mMorse["-.."]   = 'd';
    mMorse["."]     = 'e';
    mMorse["..-."]  = 'f';
    mMorse["--."]   = 'g';
    mMorse["...."]  = 'h';
    mMorse[".."]    = 'i';
    mMorse[".---"]  = 'j';
    mMorse["-.-"]   = 'k';
    mMorse[".-.."]  = 'l';
    mMorse["--"]    = 'm';
    mMorse["-."]    = 'n';
    mMorse["---"]   = 'o';
    mMorse[".--."]  = 'p';
    mMorse["--.-"]  = 'q';
    mMorse[".-."]   = 'r';
    mMorse["..."]   = 's';
    mMorse["-"]     = 't';
    mMorse["..-"]   = 'u';
    mMorse["...-"]  = 'v';
    mMorse[".--"]   = 'w';
    mMorse["-..-"]  = 'x';
    mMorse["-.--"]  = 'y';
    mMorse["--.."]  = 'z';
    
    vector<string> vStr;
    int start = 0;
    int end = letter.find(" ");
    while (end != string::npos)
    {
        vStr.push_back(letter.substr(start, (end - start)));
        start = end + 1;
        end = letter.find(" ", start);
    }
    vStr.push_back(letter.substr(start));
    
    for (auto& s : vStr)
    {
        answer += mMorse[s];
    }
    
    return answer;
}