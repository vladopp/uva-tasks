#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	ull t;
	cin >> t;
	while (t--) {
		ull n;
		cin >> n;
		if(n < 2) {
			cout << n << endl; // 0 or 1 as input
			continue;
		}

		ull divisors[10];
		memset(divisors, 0, sizeof(divisors));
		for (int divisor = 9; divisor > 1; divisor--) {
			while (n % divisor == 0) {
				n/=divisor;
				divisors[divisor]++;
			}
		}

		if(n == 1) {
			for(int i=1; i<10; i++) {
				while(divisors[i]--) {
					cout << i;
				}
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}

	return 0;
}
