#include <string>
#include <vector>

using namespace std;

int TimeStrToSeconds(const string& time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

int TimeClamp(const int& cur, const int& start, const int& end, const int& len)
{
    int s = cur;
    s = (s < 0 ? 0 : s);
    s = (s > len ? len : s);
    s = (start <= s && s <= end ? end : s);
    return s;
}

string SecondToTime(const int& inSecond)
{
    string time = "";
    
    int m = inSecond / 60;
    int s = inSecond % 60;
    
    string strM = to_string(m);
    string strS = to_string(s);
    
    strM = (strM.size() == 1 ? "0" + strM : strM);
    strS = (strS.size() == 1 ? "0" + strS : strS);
    
    time += strM;
    time += ":";
    time += strS;
    
    return time;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int len = TimeStrToSeconds(video_len);
    int cur = TimeStrToSeconds(pos);
    int start = TimeStrToSeconds(op_start);
    int end = TimeStrToSeconds(op_end);
    
    cur = TimeClamp(cur, start, end, len);
    for (auto& c : commands)
    {
        if (c == "next")
            cur += 10;
        else if (c == "prev")
            cur -= 10;
        
        cur = TimeClamp(cur, start, end, len);
    }
    
    answer = SecondToTime(cur);
    
    return answer;
}