#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull getDivisorCount(ull x) {
	int cnt = 1;
	if (x != 1) {
		++cnt;
	}

	for (ull i = 2; i * i <= x; i++) {
		cnt += 2;
		if (i * i == x) {
			--cnt;
		}
	}

	return cnt;
}

int main() {
	ull n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		if (getDivisorCount(n) % 2 == 0) {
			cout << "no" << endl;
		} else {
			cout << "yes" << endl;
		}
	}
	return 0;
}
