#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, com, num;
	vector<int> x(5);
	string s;
	cin >> n;
	while (n) {
		unordered_map<string, int> m;
		while (n--) {
			cin >> x.at(0) >> x.at(1) >> x.at(2) >> x.at(3) >> x.at(4);
			sort(x.begin(), x.end());
			s = "";
			for (auto i : x) {
				s += to_string(i);
			}
			if (m.find(s) == m.end()) {
				m.insert(make_pair(s, 1));
			} else {
				m.at(s)++;
			}
		}
		com = 0;
		num = 0;
		for (auto i : m) {
			if (i.second > com) {
				com = i.second;
				num = 1;
			} else if (i.second == com) {
				num++;
			}
		}
		cout << com*num << "\n";
		
		cin >> n;
	}
	
	return 0;
}