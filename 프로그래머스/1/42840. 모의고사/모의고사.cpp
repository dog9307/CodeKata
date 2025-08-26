#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int right[3], maxRight;
	right[0] = 0;
	right[1] = 0;
	right[2] = 0;
	maxRight = 0;
	for (int i = 0; i < answers.size(); ++i)
	{
		// 수포자 1
		if ((i % 5) + 1 == answers[i])
			++right[0];

		// 수포자 2
		if (i % 2 == 0 &&
			answers[i] == 2)
			++right[1];
		else
		{
			if (i % 8 == 1 &&
				answers[i] == 1)
				++right[1];
			else if (i % 8 == 3 &&
				answers[i] == 3)
				++right[1];
			else if (i % 8 == 5 &&
				answers[i] == 4)
				++right[1];
			else if (i % 8 == 7 &&
				answers[i] == 5)
				++right[1];
		}

		// 수포자 3
		if ((i % 10 == 0 || i % 10 == 1) &&
			answers[i] == 3)
			++right[2];
		else if ((i % 10 == 2 || i % 10 == 3) &&
			answers[i] == 1)
			++right[2];
		else if ((i % 10 == 4 || i % 10 == 5) &&
			answers[i] == 2)
			++right[2];
		else if ((i % 10 == 6 || i % 10 == 7) &&
			answers[i] == 4)
			++right[2];
		else if ((i % 10 == 8 || i % 10 == 9) &&
			answers[i] == 5)
			++right[2];
	}
    
    for (int i = 0; i < 3; ++i)
    {
		if (right[i] > maxRight)
			maxRight = right[i];
    }

	for (int i = 0; i < 3; ++i)
	{
		if (right[i] == maxRight)
			answer.push_back(i + 1);
	}

	return answer;
}