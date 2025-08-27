#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> canSpeak({"aya", "ye", "woo", "ma"});
    
    for (int i = 0; i < babbling.size(); ++i)
    {
        string currentBabbling = babbling[i];
        string prev = "";
        bool isReplace = false;
        while (currentBabbling.size() != 0)
        {
            isReplace = false;
            int pos;
            for (int j = 0; j < canSpeak.size(); ++j)
            {
                if (prev == canSpeak[j]) continue;
                
                int pos = currentBabbling.find(canSpeak[j]);
                if (pos == 0)
                {
                    isReplace = true;
                    currentBabbling.replace(0, canSpeak[j].size(), "");
                    prev = canSpeak[j];
                    break;
                }
            }
            
            if (!isReplace)
                break;
        }
        
        if (currentBabbling.size() == 0)
        {
            answer++;
        }
    }
    
    return answer;
}