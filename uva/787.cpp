#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	ll x, sum, negsum, cmax, tmp;
	bool zero;
	while (cin >> x) {
		sum = 0;
		negsum = 0;
		cmax = -INF;
		zero = false;
		while (x != -999999) {
			if (x == 0) zero = true;
			if (x >= 0) {
				if (sum == 0) sum = x;
				else sum *= x;
				negsum *= x;
			} else if (x < 0) {
				tmp = sum;
				sum = 0;
				if (negsum < 0) sum = negsum*x;
				if (tmp == 0) negsum = x;
				else negsum = tmp*x;
			}
			//cout << x << " " << sum << " " << negsum << endl;
			if (!(!zero && sum == 0)) cmax = max(cmax, sum);
			if (!(!zero && negsum == 0))cmax = max(cmax, negsum);
			
			cin >> x;
		}
		cout << cmax << "\n";
	}
	
	return 0;
}