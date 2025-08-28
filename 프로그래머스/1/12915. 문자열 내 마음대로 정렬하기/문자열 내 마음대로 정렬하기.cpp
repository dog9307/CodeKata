#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int index = 0;
bool compare(const string& s1, const string& s2)
{
    if (s1[index] == s2[index])
    {
        return s1 < s2;
    }
    else
    {
        return s1[index] < s2[index];
    }
}

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
    
    index = n;
    sort(strings.begin(), strings.end(), compare);
    

	return strings;
}