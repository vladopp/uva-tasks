#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll xGCD(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1, gcd = xGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}

int main() {
	ll a, b, x = 99999999999, y = 99999999999;
	while (cin >> a >> b) {
		ll d = xGCD(a, b, x, y);
		cout << x << " " << y << " " << d << endl;
	}

	return 0;
}
