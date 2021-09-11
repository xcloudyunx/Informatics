#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

string key = "01234";

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int R, C;
	cin >> R >> C;
	
	if (C == 2) {
		vii table(R);
		for (int i=0; i<R; i++) cin >> table[i].first >> table[i].second;
		
		struct {
			bool operator()(ii a, ii b) const {
				if (a.first != b.first) return a.first < b.first;
				return a.second < b.second;
			}
		} oneAtwoA;
		
		struct {
			bool operator()(ii a, ii b) const {
				if (a.first != b.first) return a.first > b.first;
				return a.second < b.second;
			}
		} oneDtwoA;
		
		struct {
			bool operator()(ii a, ii b) const {
				if (a.first != b.first) return a.first < b.first;
				return a.second > b.second;
			}
		} oneAtwoD;
		
		struct {
			bool operator()(ii a, ii b) const {
				if (a.first != b.first) return a.first > b.first;
				return a.second > b.second;
			}
		} oneDtwoD;
		
		struct {
			bool operator()(ii a, ii b) const {
				if (a.second != b.second) return a.second < b.second;
				return a.first < b.first;
			}
		} twoAoneA;
		
		struct {
			bool operator()(ii a, ii b) const {
				if (a.second != b.second) return a.second > b.second;
				return a.first < b.first;
			}
		} twoDoneA;
		
		struct {
			bool operator()(ii a, ii b) const {
				if (a.second != b.second) return a.second < b.second;
				return a.first > b.first;
			}
		} twoAoneD;
		
		struct {
			bool operator()(ii a, ii b) const {
				if (a.second != b.second) return a.second > b.second;
				return a.first > b.first;
			}
		} twoDoneD;
		
		auto c = table;
		sort(c.begin(), c.end(), oneAtwoA);
		if (table == c) {
			cout << "1 asc\n2 asc";
			return 0;
		}
		sort(c.begin(), c.end(), oneAtwoD);
		if (table == c) {
			cout << "1 asc\n2 desc";
			return 0;
		}
		sort(c.begin(), c.end(), oneDtwoA);
		if (table == c) {
			cout << "1 desc\n2 asc";
			return 0;
		}
		sort(c.begin(), c.end(), oneDtwoD);
		if (table == c) {
			cout << "1 desc\n2 desc";
			return 0;
		}
		sort(c.begin(), c.end(), twoAoneA);
		if (table == c) {
			cout << "2 asc\n1 asc";
			return 0;
		}
		sort(c.begin(), c.end(), twoAoneD);
		if (table == c) {
			cout << "2 asc\n1 desc";
			return 0;
		}
		sort(c.begin(), c.end(), twoDoneA);
		if (table == c) {
			cout << "2 desc\n1 asc";
			return 0;
		}
		sort(c.begin(), c.end(), twoDoneD);
		if (table == c) {
			cout << "2 desc\n1 desc";
			return 0;
		}
		
	} else {
		vector<vi> table(C, vi(R));
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) cin >> table[i][j];
		}
		
		struct {
			bool operator()(vi &a, vi &b) const {
				return ascending();
			}
		} asc;
		
		struct {
			bool operator()(vi &a, vi &b) const {
				return descending();
			}
		} desc;
		
		do {
			x 
		} while (next_permutation(key));
	}
	
	
	
	return 0;
}