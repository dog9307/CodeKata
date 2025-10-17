#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer.resize(arr1.size());
    int col = 0;
    for (int i = 0; i < answer.size(); ++i)
    {
        answer[i].resize(arr2[0].size());
        for (int j = 0; j < answer[i].size(); ++j)
        {
            int sum = 0;
            
            for (int k = 0; k < arr2.size(); ++k)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            
            answer[i][j] = sum;
        }
        
    }
    return answer;
}