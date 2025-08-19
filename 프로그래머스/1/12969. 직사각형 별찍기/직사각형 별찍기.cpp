#include <iostream>

using namespace std;

int main(void) {
	int a;
	int b;
	cin >> a >> b;

	char* c = new char[a + 1];
	for (int i = 0; i < a; ++i)
    {
		c[i] = '*';
    }
	c[a] = '\0';
    
	for (int i = 0; i < b; ++i)
		cout << c << endl;

	delete[] c;
    
    return 0;
}