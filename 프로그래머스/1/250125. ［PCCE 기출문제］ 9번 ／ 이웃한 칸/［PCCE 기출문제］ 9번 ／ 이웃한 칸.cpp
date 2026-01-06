#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    // left right up down
    int dx[4] = { -1, 1,  0, 0 };
    int dy[4] = {  0, 0, -1, 1 };
    
    for (int i = 0; i < 4; ++i)
    {
        int cx = w + dx[i];
        int cy = h + dy[i];
        if (cx < 0 || cx >= board[0].size()) continue;
        if (cy < 0 || cy >= board.size()) continue;
        
        if (board[h][w] == board[cy][cx])
        {
            ++answer;
        }
    }
    
    return answer;
}