#include <string>
#include <vector>

#include <stack>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    
    vector<stack<int>> vs;
    
    vs.resize(w);
    for (int i = 1; i <= n; ++i)
    {
        int temp = i - 1;
        int col = temp / w;
        int row = temp % w;
        row = (col % 2 == 0 ? row : w - row - 1);
        
        vs[row].push(i);
    }
    
    int targetCol = (num - 1) / w;
    int targetRow = (num - 1) % w;
    targetRow = (targetCol % 2 == 0 ? targetRow : w - targetRow - 1);
    while (vs[targetRow].size() > 0)
    {
        if (vs[targetRow].top() == num) break;
        
        vs[targetRow].pop();
        ++answer;
    }
    
    return answer;
}