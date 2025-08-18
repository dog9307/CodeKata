#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	
	for (int i = 0; i < seoul.size(); ++i)
	{
		if (seoul[i] == "Kim")
		{
			//string number = "";
			//while (i > 0)
			//{
			//	number = (char)(i % 10 + '0') + number;
			//	i /= 10;
			//}

			return ("김서방은 " + to_string(i) + "에 있다");
		}
	}

	return answer;
}