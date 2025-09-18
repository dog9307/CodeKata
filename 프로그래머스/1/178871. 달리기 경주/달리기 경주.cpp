#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> mP;
    for (int i = 0; i < players.size(); ++i)
    {
        mP[players[i]] = i;
    }
    
    for (int i = 0; i < callings.size(); ++i)
    {
        int idx = mP[callings[i]];
        
        mP[players[idx - 1]] += 1;
        mP[callings[i]] -= 1;
        
        swap(players[idx], players[idx - 1]);
    }
    
    return players;
}