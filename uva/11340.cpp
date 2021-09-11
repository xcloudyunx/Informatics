#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K, b, M, total;
	char a;
	string s;
	cin >> N;
	
	while (N--) {
		cin >> K;
		unordered_map<char, int> dict;
		while (K--) {
			cin >> a >> b;
			dict.insert(make_pair(a, b));
		}
		cin >> M;
		cin.ignore();
		total = 0;
		while (M--) {
			getline(cin, s);
			for (auto i : s) {
				if (dict.find(i) != dict.end()) {
					total += dict.at(i);
				}
			}
		}
		printf("%d.%02d$\n", total/100, total%100);
	}
	
	return 0;
}