#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string s) {
	int answer = 0;
	bool isMinus = (s[0] == '-');
	int startIndex = 0;

	if (isMinus || s[0] == '+')
		startIndex = 1;

	for (int i = startIndex; i < s.length(); ++i)
	{
		if (i != startIndex)
			answer *= 10;

		answer += (s[i] - '0');
	}

	if (isMinus)
		answer *= (-1);

	return answer;
}