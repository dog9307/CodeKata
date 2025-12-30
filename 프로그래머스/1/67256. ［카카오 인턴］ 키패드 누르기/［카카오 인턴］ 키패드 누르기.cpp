#include <string>
#include <vector>

#include <map>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    map<int, Point> mNum;
    mNum[0] = {1, 3};
    mNum[1] = {0, 0};
    mNum[2] = {1, 0};
    mNum[3] = {2, 0};
    mNum[4] = {0, 1};
    mNum[5] = {1, 1};
    mNum[6] = {2, 1};
    mNum[7] = {0, 2};
    mNum[8] = {1, 2};
    mNum[9] = {2, 2};
    mNum['*'] = {0, 3};
    mNum['#'] = {2, 3};
    
    int left = '*';
    int right = '#';
    
    for (auto& n : numbers)
    {
        if (n == 1 ||
           n == 4 ||
           n == 7 ||
           n == '*')
        {
            left = n;
            answer += "L";
        }
        else if (n == 3 ||
                n == 6 ||
                n == 9 ||
                n == '#')
        {
            right = n;
            answer += "R";
        }
        else if (n == 2 ||
                n == 5 ||
                n == 8 ||
                n == 0)
        {
            Point& leftPoint = mNum[left];
            Point& rightPoint = mNum[right];
            Point& targetPoint = mNum[n];
            
            int ld = abs(targetPoint.x - leftPoint.x) + abs(targetPoint.y - leftPoint.y);
            int rd = abs(targetPoint.x - rightPoint.x) + abs(targetPoint.y - rightPoint.y);
            
            if (ld < rd)
            {
                left = n;
                answer += "L";
            }
            else if (rd < ld)
            {
                right = n;
                answer += "R";
            }
            else
            {
                if (hand == "left")
                {
                    left = n;
                    answer += "L";
                }
                else if (hand == "right")
                {
                    right = n;
                    answer += "R";
                }
            }
        }
    }
        
    return answer;
}