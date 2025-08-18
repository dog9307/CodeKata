#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;

	answer.resize(n);
	for (int i = 1; i <= n; ++i)
		answer[i - 1] = x * i;

	return answer;
}