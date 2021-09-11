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
	string tmp;
	for (int i=1; N; i++) {
		unordered_set<string> s;
		for (int j=0; j<N; j++) {
			getline(cin, tmp);
			s.insert(tmp);
		}
		cout << "Week " << i << " " << s.size() << "\n";
		
		cin >> N;
	}
}