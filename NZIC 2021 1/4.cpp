#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	ll N;
	cin >> N;
	string n = to_string(N);
	ll l = n.length();
	ll count = 0, x;
	
	vector<ll> t = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000, 10000000000, 110000000000, 1200000000000, 13000000000000, 140000000000000, 1500000000000000, 16000000000000000};
	
	for (ll i=0; i<l; i++) {
		x = n[i]-'0';
		if (x > 3) {
			count += pow(10, l-i-1);
		} else if (x == 3) {
			count += N%(ll)pow(10, l-i-1) + 1;
		}
		count += x*t[l-i-1];
	}
	
	cout << count;
	
	return 0;
}