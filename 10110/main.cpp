#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

bool hasOddDivisorCount(ull x) {
	return ((ull)sqrt(x)) * ((ull)sqrt(x)) == x;
}

int main() {
	ull n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		if (!hasOddDivisorCount(n)) {
			cout << "no" << endl;
		} else {
			cout << "yes" << endl;
		}
	}
	return 0;
}
