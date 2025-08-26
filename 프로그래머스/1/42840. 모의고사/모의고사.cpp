#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
    vector<int> right1({1, 2, 3, 4, 5});
    vector<int> right2({2, 1, 2, 3, 2, 4, 2, 5});
    vector<int> right3({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    vector<int> stu({0, 0, 0});
    
    int max = 0;
    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == right1[i % right1.size()])
        {
            stu[0]++;
            if (max < stu[0])
                max = stu[0];
        }
        
        if (answers[i] == right2[i % right2.size()])
        {
            stu[1]++;
            if (max < stu[1])
                max = stu[1];
        }
        
        if (answers[i] == right3[i % right3.size()])
        {
            stu[2]++;
            if (max < stu[2])
                max = stu[2];
        }
    }
    
    for (int i = 0; i < stu.size(); ++i)
    {
        if (max == stu[i])
            answer.push_back(i + 1);
    }
    

	return answer;
}