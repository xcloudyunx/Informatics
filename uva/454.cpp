#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	string s, x;
	cin >> T;
	cin.ignore();
	cin.ignore();
	while (T--) {
		unordered_map<string, vector<string> > dict;
		getline(cin, s);
		while (s != "") {
			x = "";
			for (auto i : s) {
				if (i != ' ') {
					x.push_back(i);
				}
			}
			sort(x.begin(), x.end());
			
			if (dict.find(x) == dict.end()) {
				dict.insert({x, {s}});
			} else {
				dict.at(x).push_back(s);
			}
			
			getline(cin, s);
		}
		vector<string> phrases;
		for (auto i : dict) {
			if (i.second.size() > 1) {
				sort(i.second.begin(), i.second.end());
				for (int j=0; j<i.second.size(); j++) {
					for (int k=j+1; k<i.second.size(); k++) {
						phrases.push_back(i.second.at(j)+" = "+i.second.at(k));
					}
				}
			}
		}
		sort(phrases.begin(), phrases.end());
		
		for (auto i : phrases) {
			cout << i << "\n";
		}
		
		cout << "\n";
	}
	
	return 0;
}