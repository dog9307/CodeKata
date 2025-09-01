#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    if (a > b)
        swap(a, b);
    
    ++answer;
    while (((a + 1) / 2) != ((b + 1) / 2))
    {
        if ((a + 1) / 2 > 1)
            a = (a + 1) / 2;
        if ((b + 1) / 2 > 1)
            b = (b + 1) / 2;
        
        ++answer;
    }

    return answer;
}