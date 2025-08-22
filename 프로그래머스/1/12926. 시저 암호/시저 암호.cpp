#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	for (int i = 0; i < s.length(); ++i)
	{
        char target;
		if ('a' <= s[i] && s[i] <= 'z')
        {
            target = 'a';
            s[i] = ((s[i] - target + n) % 26) + target;
        }
		else if ('A' <= s[i] && s[i] <= 'Z')
        {
            target = 'A';
            s[i] = ((s[i] - target + n) % 26) + target;
        }
	}

	return s;
}