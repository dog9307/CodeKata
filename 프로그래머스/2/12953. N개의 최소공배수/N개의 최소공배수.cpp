#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int GDC(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return GDC(b ,a % b);
}

int LSM(int a, int b)
{
    return a * b / GDC(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    sort(arr.begin(), arr.end());
    answer = LSM(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); ++i)
    {
        int a = answer;
        int b = arr[i];
        
        answer = (a < b ? LSM(a, b) : LSM(b, a));
    }
    
    return answer;
}