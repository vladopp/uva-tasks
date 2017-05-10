#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

int main() {
	int t;
	cin >> t;

	while (t--) {
		ull a, b, diff, steps, initial;
		cin >> a >> b;
		diff = b - a;

		if (diff == 0) {
			cout << 0 << endl;
			continue;
		}

		initial = floor(sqrt(diff));
		diff -= initial * initial;
		steps = (initial) * 2 - 1; // steps needed to get from 1 to initial to 1

		for (ull i = min(initial, diff); i > 0; --i) {
			steps += diff / i;
			diff -= i * floor(diff / i);
		}

		cout << steps << endl;
	}

	return 0;
}
