#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    for (int i = 0; i < order.size(); ++i)
    {
        if (order[i] == "anything")
            order[i] = "americano";
        
        int price = 0;
        if (order[i].find("americano") != string::npos)
        {
            price = 4500;
        }
        else if (order[i].find("cafelatte") != string::npos)
        {
            price = 5000;
        }
        
        answer += price;
    }
    
    return answer;
}