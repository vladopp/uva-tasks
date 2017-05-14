#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull MAX_N = 100500;
bool primes[MAX_N];
vector<ull> primesVector;

void sieve() {
	memset(primes, true, sizeof(primes));

	for (ull i = 2; i * i < MAX_N; i++) {
		if (primes[i]) {
			for (ull j = i * i; j < MAX_N; j += i) {
				primes[j] = false;
			}
		}
	}

	for (ull i = 2; i < MAX_N; i++) {
		if (primes[i]) {
			primesVector.push_back(i);
		}
	}
}

ull getDigitSum(ull num) {
	ull digitSum = 0;

	while (num > 0) {
		digitSum += num % 10;
		num /= 10;
	}

	return digitSum;
}

bool check(ull n, ull digitSum) {
	ull sum = 0;
	ull divisors = 0;
	for (ull i = 0; i < primesVector.size(); i++) {
		ull prime = primesVector[i];
		if (prime >= n) {
			break;
		}
		while (n % prime == 0) {
			n /= prime;
			sum += getDigitSum(prime);
			divisors++;
		}
	}

	if (n != 1) {
		sum += getDigitSum(n);
	}

	return sum == digitSum && divisors > 0;
}

int main() {
	sieve();
	ull n, t;
	cin >> t;
	while (t--) {
		cin >> n;

		while (true) {
			n += 1;
			ull digitSum = getDigitSum(n);
			if (check(n, digitSum)) {
				cout << n << endl;
				break;
			}

		}

	}

	return 0;
}
