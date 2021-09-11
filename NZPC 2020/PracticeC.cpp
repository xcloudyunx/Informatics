#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N;
	cin >> N;
	int S, F, C;
	string s;
	int total;
	for (int z=0; z<N; z++) {
		total = 0;
		cin >> S >> F >> C;
		
		for (int i=S; i<=F; i++) {
			s = to_string(i);
			for (auto j : s) {
				if (j-'0' == C) total++;
			}
		}
		
		cout << total << "\n";
	}
}