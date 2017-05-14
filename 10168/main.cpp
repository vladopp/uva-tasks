#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const ull MAX_N = 10000005;
bool primes[MAX_N];
vector<ull> primesVector;

void sieve() {
	memset(primes, true, sizeof(primes));

	for (ull i = 2; i * i < MAX_N; i++) {
		if (primes[i]) {
			for (ull j = i * i; j < MAX_N; j += i) {
				primes[j] = false;
			}
			primesVector.push_back(i);
		}
	}

}

int main() {
	sieve();
	ull n;
	while (cin >> n) {
		if (n < 8) {
			cout << "Impossible." << endl;
		} else {
			if (n % 2) {
				cout << "2 3 ";
				n -= 5;
			} else {
				n -= 4;
				cout << "2 2 ";
			}
			for (ull i = 0; i < MAX_N; i++) {
				ull prime = primesVector[i];
				if (primes[n - prime]) {
					cout << prime << " " << n - prime << endl;
					break;
				}
			}
		}
	}
	return 0;
}
