#include <bits/stdc++.h>

using namespace std;

int main() {
	int TC = 1;
	unordered_map<char, int> alphabet = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24}, {'Z', 25}};
	string s;
	bool broken;
	cin >> s;
	
	while (s != "end") {
		vector< pair<int, int> > v(26, make_pair(INT_MAX, -1));
		for (int i=0; i<s.size(); i++) {
			if (i < v.at(alphabet.at(s.at(i))).first) {
				v.at(alphabet.at(s.at(i))).first = i;
			}
			if (i > v.at(alphabet.at(s.at(i))).second) {
				v.at(alphabet.at(s.at(i))).second = i;
			}
		}
		stack< pair<int, int> > letters;
		for (auto i : v) {
			if (i.first != INT_MAX) {
				letters.push(i);
			}
		}
		set<int> stacks;
		stacks.insert(letters.top().second);
		letters.pop();
		while (!letters.empty()) {
			broken = false;
			for (auto it=stacks.rbegin(); it!=stacks.rend(); it++) {
				if (letters.top().first > *it) {
					stacks.erase(*it);
					stacks.insert(letters.top().second);
					letters.pop();
					broken = true;
					break;
				} 
			}
			if (!broken) {
				stacks.insert(letters.top().second);
				letters.pop();
			}
		}
		cout << "Case " << TC++ << ": " << stacks.size() << "\n";
		cin >> s;
	}
	
	return 0;
}
