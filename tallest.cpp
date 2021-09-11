#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	while (N) {
		vector< pair<float, string> > h(N);
		float height = 0;
		for (int i=0; i<N; i++) {
			cin >> h.at(i).second >> h.at(i).first;
			height = max(height, h.at(i).first*100);
		}
		for (auto i : h) {
			if (i.first*100 == height) {
				cout << i.second << " ";
			}
		}
		cout << endl;
		cin >> N;
	}
}