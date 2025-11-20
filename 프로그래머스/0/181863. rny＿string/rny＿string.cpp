#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    
    int pos = rny_string.find("m");
    while (pos != string::npos)
    {
        rny_string.replace(pos, 1, "rn");
        pos = rny_string.find("m");
    }
    
    return rny_string;
}