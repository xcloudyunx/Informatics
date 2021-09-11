#include <bits/stdc++.h>

using namespace std;

string lower(string s) {
	string x = s;
	for (int i=0; i<s.size(); i++) {
		x.at(i) = tolower(s.at(i));
	}
	return x;
}

int main() {
	string s, x;
	unordered_map<string, vector<string> > dict;
	cin >> s;
	while (s != "#") {
		x = lower(s);
		sort(x.begin(), x.end());
		if (dict.find(x) == dict.end()) {
			dict.insert({x, {s}});
		} else {
			dict.at(x).push_back(s);
		}
		
		cin >> s;
	}
	vector<string> ananagram;
	for (auto i : dict) {
		if (i.second.size() == 1) {
			ananagram.push_back(i.second.at(0));
		}
	}
	sort(ananagram.begin(), ananagram.end());
	
	for (auto i : ananagram) {
		cout << i << "\n";
	}
	
	return 0;
}