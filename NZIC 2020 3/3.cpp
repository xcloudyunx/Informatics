#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	vector<string> t(5);
	for (int i=0; i<5; i++) {
		cin >> t[i];
	}
	
	set<char> s;
	string type = "ok";
	for (auto c : t[0]) {
		if (s.find(c) != s.end()) {
			type = "best";
			break;
		}
		s.insert(c);
	}
	
	if (type == "best") {
		for (int i=1; i<5; i++) {
			if (t[i].size()%2 != 1) {
				cout << "bad";
				return 0;
			}
		}
		cout << "best";
	} else {
		for (int i=1; i<4; i++) {
			if (t[i].size() <= t[i+1].size()) {
				cout << "bad";
				return 0;
			}
		}
		cout << "ok";
	}
	
	return 0;
}