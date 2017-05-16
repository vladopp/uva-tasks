#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ull MAX = 51;

ull ways[MAX];

ull calc(ull length) {
	if(ways[length] == 0 && length > 2) {
		ways[length] = calc(length-1) + calc(length-2);
	}

	return ways[length];
}

int main() {
	ways[1] = 1;
	ways[2] = 2;

	ull length;
	while (cin >> length) {
		if (length == 0) {
			break;
		}

		if (ways[length] == 0) {
			calc(length);
		}

		cout << ways[length] << endl;
	}

	return 0;
}
