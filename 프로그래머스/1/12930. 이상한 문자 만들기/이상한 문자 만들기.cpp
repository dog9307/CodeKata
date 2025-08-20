#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	bool isOdd = true;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			isOdd = true;
			continue;
		}

		if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
		{
			if (isOdd)
				s[i] = toupper(s[i]);
			else
				s[i] = tolower(s[i]);
		}

		isOdd = !isOdd;
	}

	return s;
}