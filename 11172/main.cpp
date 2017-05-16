#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
	ull tests;
	cin >> tests;
	while (tests--) {
		ll a, b;
		cin >> a >> b;
		if (a > b) {
			cout << ">" << endl;
		} else if (a < b) {
			cout << "<" << endl;
		} else {
			cout << "=" << endl;
		}
	}

	return 0;
}
