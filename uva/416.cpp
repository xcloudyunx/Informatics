#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

vector<string> digit = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
int N;
bool sol;

pair<bool, int> possible(string s, int i, int broken) {
	string x = digit[i];
	for (int k=0; k<7; k++) {
		if (broken & (1<<k) && s[k] == 'Y') return {false, 0};
		if (broken & (1<<k)) x[k] = 'N';
		if (s[k] == 'N' && x[k] == 'Y') {
			x[k] = 'N';
			broken |= (1<<k);
		}
	}
	if (s != x) return {false, 0};
	else return {true, broken};
}

void backtrack(int n, int current, int broken, vector<string> &led) {
	if (sol) return;
	if (n == N) sol = true;
	else {
		if (current == 0) return;
		auto tmp = possible(led[n], current-1, broken);
		if (tmp.first) {
			backtrack(n+1, current-1, tmp.second, led);
		}
	}
}

int main() {
	cin >> N;
	while (N) {
		vector<string> led(N);
		for (int i=0; i<N; i++) cin >> led[i];
		sol = false;
		for (int i=10; i>0; i--) {
			backtrack(0, i, 0, led);
		}
		if (sol) cout << "MATCH\n";
		else cout << "MISMATCH\n";
		
		cin >> N;
	}
	
	return 0;
}