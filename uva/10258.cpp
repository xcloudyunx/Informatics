#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, c, p, t;
	string s;
	char l[2];
	cin >> T;
	cin.ignore();
	cin.ignore();
	while (T--) {
		unordered_map<int, pair< unordered_map<int, int>, pair<int, int> > > data; //contestant number, (problem number, attempts), score, time
		getline(cin, s);
		while (s != "") {
			sscanf(s.c_str(), "%d %d %d %s", &c, &p, &t, l);
			if (data.find(c) == data.end()) {
				data.insert(make_pair(c, make_pair(unordered_map<int, int>{}, make_pair(0, 0))));
			}
			if (strcmp(l, "C") == 0) {
				if (data.at(c).first.find(p) != data.at(c).first.end()) {
					if (data.at(c).first.at(p) > 0) {
						data.at(c).second.second += 20*data.at(c).first.at(p);
						data.at(c).second.first++;
						data.at(c).second.second += t;
						data.at(c).first.at(p) = 0;
					}
				} else {
					data.at(c).second.first++;
					data.at(c).second.second += t;
					data.at(c).first.insert(make_pair(p, 0));
				}
			} else if (strcmp(l, "I") == 0) {
				if (data.at(c).first.find(p) == data.at(c).first.end()) {
					data.at(c).first.insert(make_pair(p, 1));
				} else if (data.at(c).first.at(p) != 0) {
					data.at(c).first.at(p)++;
				}
			}
			
			getline(cin, s);
		}
		
		vector< tuple<int, int, int> > board; //score, time, contestant number
		for (auto i : data) {
			board.push_back(make_tuple(i.second.second.first, i.second.second.second, i.first));
		}
		struct {
			bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) const {
				if (get<0>(a) != get<0>(b)) {
					return get<0>(a) > get<0>(b);
				} else if (get<1>(a) != get<1>(b)) {
					return get<1>(a) < get<1>(b);
				} else {
					return get<2>(a) < get<2>(b);
				}
			}
		} csort;
		sort(board.begin(), board.end(), csort);
		
		for (auto i : board) {
			cout << get<2>(i) << " " << get<0>(i) << " " << get<1>(i) << "\n";
		}
		cout << "\n";
	}
	
	return 0;
}