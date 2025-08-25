#include <string>
#include <vector>

using namespace std;

enum DAYS
{
	SUN,
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	END
};

string solution(int a, int b) {
	string answer = "";

	int year = 2016;
	int month = 1;
	int day = 1;
	int dayName = FRI;

	while (!(month == a && day == b))
	{
		day++;
		switch (month)
		{
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (day % 32 == 0)
                {
                    day = 1;
                    month++;
                }
			break;

            case 2:
                if (year % 4 == 0)
                {
                    if (day % 30 == 0)
                    {
                        day = 1;
                        month++;
                    }
                }
                else
                {
                    if (day % 29 == 0)
                    {
                        day = 1;
                        month++;
                    }
                }
			break;

            case 4: case 6: case 9: case 11:
                if (day % 31 == 0)
                {
                    day = 1;
                    month++;
                }
			break;
		}

		dayName++;
		if (dayName % END == 0)
			dayName = 0;
	}

	switch (dayName)
	{
        case SUN:
            answer = "SUN";
		break;
        case MON:
            answer = "MON";
		break;
        case TUE:
            answer = "TUE";
		break;
        case WED:
            answer = "WED";
		break;
        case THU:
            answer = "THU";
		break;
        case FRI:
            answer = "FRI";
		break;
        case SAT:
            answer = "SAT";
		break;
	}

	return answer;
}