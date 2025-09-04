#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

    map<int, int> stuMap;
    for (int i = 1; i <= n; ++i)
        stuMap[i] = 1;
    
    for (auto& l : lost)
    {
        map<int, int>::iterator iter = stuMap.find(l);
        if (iter != stuMap.end())
        {
            --(iter->second);
        }
    }
    
    for (auto& r : reserve)
    {
        map<int, int>::iterator iter = stuMap.find(r);
        if (iter != stuMap.end())
        {
            ++(iter->second);
        }
    }
    
    for (int i = 1; i < n; ++i)
    {
        if (stuMap[i] <= 0 && stuMap[i + 1] >= 2)
        {
            ++stuMap[i];
            --stuMap[i + 1];
        }
        else if (stuMap[i] >= 2 && stuMap[i + 1] <= 0)
        {
            --stuMap[i];
            ++stuMap[i + 1];
        }
    }
    if (stuMap[n] <= 0 && stuMap[n - 1] >= 2)
    {
        ++stuMap[n];
        --stuMap[n - 1];
    }
    else if (stuMap[n] >= 2 && stuMap[n - 1] <= 0)
    {
        --stuMap[n];
        ++stuMap[n - 1];
    }
    
    for (auto& s : stuMap)
    {
        answer += (s.second >= 2 ? 1 : s.second);
    }
	

	return answer;
}