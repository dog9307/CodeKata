#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    map<int, bool> cleanMap;
    for (int i = 1; i <= n; ++i)
    {
        cleanMap[i] = true;
    }
    for (int i = 0; i < section.size(); ++i)
    {
        cleanMap[section[i]] = false;
    }
    
    bool isAllClean = false;
    int currentIndex = 0;
    int startSection = section[currentIndex];
    
    while(!isAllClean)
    {
        while (cleanMap[section[currentIndex]] && currentIndex < section.size())
        {
            currentIndex++;
        }
        if (currentIndex >= section.size())
        {
            isAllClean = true;
            break;
        }
        
        startSection = section[currentIndex];
        
        for (int i = startSection; i < startSection + m; ++i)
        {
            cleanMap[i] = true;
        }
        answer++;
        currentIndex++;
    }
    
    return answer;
}