#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, P, E;
	cin >> N >> P >> E;
	
	vector<string> dict(N);
	
	for (int i=0; i<N; i++) {
		cin >> dict.at(i);
	}
	
	for (int i=0; i<P; i++) {
		int m;
		cin >> m;
		double ct = 0.0f;
		for (int j=0; j<m; j++) {
			string s;
			cin >> s;
			ct += log2(find(dict.begin(), dict.end(), s) - dict.begin() + 1.0f);
		}
		
		if (ct >= E) {
			cout << "Valid" << endl;
		} else {
			cout << "Invalid" << endl;
		}
	}
	
	return 0;
}