#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;

	string number = to_string(n);
	sort(&number[0], &number[number.length()], greater<char>());

	for (int i = 0; i < number.length(); ++i)
	{
		if (i != 0)
			answer *= 10;
		answer += (int)(number[i] - '0');
	}

	return answer;
}