#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull MAX_N = 65004;
bool prime[MAX_N];

void init() {
	memset(prime, true, sizeof(prime));

	for (ull p = 2; p * p <= MAX_N; p++) {
		if (prime[p] == true) {
			for (ull i = p * 2; i <= MAX_N; i += p) {
				prime[i] = false;
			}
		}
	}
}

ull fast_power(ull base, ull power, ull mod) {
	ull result = 1;

	while (power > 0) {
		if (power % 2 == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		power = power / 2;
	}

	return result;
}

int main() {
	init();
	ull n;

	while (cin >> n) {
		if (n == 0) {
			break;
		}

		bool isSpecial = true;
		if (!prime[n]) {
			for (ull i = 2; i < n; i++) {
				if (fast_power(i, n, n) != i) {
					isSpecial = false;
					break;
				}
			}
		} else {
			isSpecial = false;
		}

		if (isSpecial) {
			cout << "The number " << n << " is a Carmichael number." << endl;
		} else {
			cout << n << " is normal." << endl;
		}
	}

	return 0;
}
