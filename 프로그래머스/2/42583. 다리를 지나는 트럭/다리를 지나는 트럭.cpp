#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	// 건너는 중인 애들
	vector<int> doing;
	vector<int> doingTime;
	while (truck_weights.size() != 0 ||
		doing.size() != 0)
	{
		++answer;

		int sum = 0;
		for (int i = 0; i < doing.size(); ++i)
			sum += doing[i];

		if (truck_weights.size() != 0)
		{
			if (sum + truck_weights[0] <= weight)
			{
				doing.push_back(truck_weights[0]);
				doingTime.push_back(0);
				truck_weights.erase(truck_weights.begin());
			}
		}

		for (int i = 0; i < doingTime.size();)
		{
			++doingTime[i];

			if (doingTime[i] >= bridge_length)
			{
				doing.erase(doing.begin() + i);
				doingTime.erase(doingTime.begin() + i);
			}
			else
				++i;
		}
	}

	return answer;
}