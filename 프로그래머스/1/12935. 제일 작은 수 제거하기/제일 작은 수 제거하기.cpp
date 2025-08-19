#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer = arr;
	sort(answer.begin(), answer.end());
	int min = answer[0];
	answer.clear();

	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == min) continue;
		answer.push_back(arr[i]);
	}

	if (answer.size() == 0)
		answer.push_back(-1);

	return answer;
}