#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	queue<string> NZ;
	queue<string> DIP;
	queue<string> ALL;
	unordered_set<string> v;
	
	for (int i=0; i<N; i++) {
		string type, value;
		cin >> type >> value;
		if (type == "NZ") {
			NZ.push(value);
		} else if (type == "DIP") {
			DIP.push(value);
		}
		ALL.push(value);
	}
	
	for (int i=0; i<K; i++) {
		string type;
		cin >> type;
		if (type == "NZ") {
			if (NZ.empty()) {
				cout << "NA" << endl;
				continue;
			}
			while (!NZ.empty() && v.find(NZ.front()) != v.end()) {
				NZ.pop();
			}
			if (NZ.empty()) {
				cout << "NA" << endl;
				continue;
			}
			cout << NZ.front() << endl;
			v.insert(NZ.front());
			NZ.pop();
		} else if (type == "DIP") {
			if (DIP.empty()) {
				cout << "NA" << endl;
				continue;
			}
			while (!DIP.empty() && v.find(DIP.front()) != v.end()) {
				DIP.pop();
			}
			if (DIP.empty()) {
				cout << "NA" << endl;
				continue;
			}
			cout << DIP.front() << endl;
			v.insert(DIP.front());
			DIP.pop();
		} else {
			if (ALL.empty()) {
				cout << "NA" << endl;
				continue;
			}
			while (!ALL.empty() && v.find(ALL.front()) != v.end()) {
				ALL.pop();
			}
			if (ALL.empty()) {
				cout << "NA" << endl;
				continue;
			}
			cout << ALL.front() << endl;
			v.insert(ALL.front());
			ALL.pop();
		}
	}
	
	return 0;
}