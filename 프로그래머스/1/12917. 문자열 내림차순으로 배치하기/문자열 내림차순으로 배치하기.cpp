#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {

	sort(&s[0], &s[s.length()], greater<char>());

	return s;
}