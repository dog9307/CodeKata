#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	answer.resize(commands.size());
	int currentCommand = 0;
	while (currentCommand < commands.size())
	{
		--commands[currentCommand][0];
		--commands[currentCommand][1];
		--commands[currentCommand][2];

		vector<int> devidedArr;
		for (int i = commands[currentCommand][0]; i <= commands[currentCommand][1]; ++i)
			devidedArr.push_back(array[i]);

		sort(devidedArr.begin(), devidedArr.end());

		answer[currentCommand] = devidedArr[commands[currentCommand][2]];
		++currentCommand;
	}

	return answer;
}