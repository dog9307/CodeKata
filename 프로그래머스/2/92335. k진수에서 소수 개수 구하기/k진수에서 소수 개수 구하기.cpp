#include <string>
#include <vector>

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string EssenceChange(int n, int k)
{
    string essence = "";
    
    while (n)
    {
        essence += (char)(n % k + '0');
        
        n /= k;
    }
    
    reverse(essence.begin(), essence.end());
    return essence;
}

void Split(const string& e, vector<string>& result)
{
    long long start = 0;
    long long end = start + 1;
    
    start = e.find('0');
    if (start >= e.size())
    {
        result.push_back(e);
        return;
    }
    end = e.find('0', start + 1);
    if (start != 0)
    {
        string sub = e.substr(0, start);
        if (sub != "1" && sub.size() > 0)
            result.push_back(sub);
    }
    while (start < e.size())
    {
        string sub = e.substr(start + 1, end - start - 1);
        if (sub != "1" && sub.size() > 0)
            result.push_back(sub);
        
        start = end;
        end = e.find('0', start + 1);
    }
}

bool IsPrime(long long num)
{
    for (long long i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string essence = EssenceChange(n, k);
    if (essence.size() <= 0) return 0;
    
    vector<string> pList;
    Split(essence, pList);
    
    for (auto& p : pList)
    {
        if (IsPrime(stol(p)))
            ++answer;
    }
    
    return answer;
}