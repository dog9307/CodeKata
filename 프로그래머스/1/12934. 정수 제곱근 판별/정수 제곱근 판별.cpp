#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
	double check = sqrt(n);
	int check2 = check;

	if (check == check2)
		return (check + 1) * (check + 1);

	return -1;
}