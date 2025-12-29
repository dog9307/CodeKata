#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    
    for (auto& q : queries)
    {
        int s = q[0];
        int e = q[1];
        
        for (int i = s; i <= e; ++i)
        {
            ++arr[i];
        }
    }
    
    return arr;
}