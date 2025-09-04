#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int correct = 0;
    int incorrect = 0;
    
    int currentIndex = 0;
    
    while (currentIndex < s.size())
    {
        correct = 1;
        incorrect = 0;
        
        for (int i = currentIndex + 1; i < s.size(); ++i)
        {
            if (s[currentIndex] == s[i])
            {
                ++correct;
            }
            else
            {
                ++incorrect;
            }
            
            if (correct == incorrect)
            {
                ++answer;
                currentIndex = i;
                break;
            }
            else if (i + 1 >= s.size())
            {
                currentIndex = i;
            }
        }
        
        ++currentIndex;
        if (correct != incorrect && currentIndex >= s.size())
        {
            ++answer;
        }
    }
    
    return answer;
}