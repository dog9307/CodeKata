#include <string>
#include <vector>

#include <map>

#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> mList;
    for (int i = 0; i < want.size(); ++i)
    {
        mList[want[i]] = number[i];
    }    
    
    for (int i = 0; i <= discount.size() - 10; ++i)
    {
        map<string, int> tempList = mList;
        bool isSuccess = true;
        for (int j = i; j < i + 10; ++j)
        {
            auto iter = tempList.find(discount[j]);
            if (iter != tempList.end())
            {
                iter->second -= 1;
                if (iter->second < 0)
                {
                    isSuccess = false;
                    break;
                }
            }
            else
            {
                isSuccess = false;
                break;
            }
        }
        
        if (isSuccess)
            ++answer;
    }
    
    return answer;
}