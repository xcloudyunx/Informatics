#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> t(6, 0);
	map< string, vector<int> > stock;
	
	string name;
	char type;
	for (int i=0; i<N; i++) {
		cin >> name >> type;
		if (type == 'G') {
			t.at(0)++;
		} else if (type == 'C') {
			t.at(1)++;
		} else if (type == 'E') {
			t.at(2)++;
		} else if (type == 'P') {
			t.at(3)++;
		} else if (type == 'L') {
			t.at(4)++;
		} else if (type == 'S') {
			t.at(5)++;
		}
	}
	
	for (int i=0; i<N; i++) {
		cin >> name;
		stock.emplace(name, vector<int> (6));
		for (int j=0; j<6; j++) {
			cin >> stock.at(name).at(j);
		}
	}
	
	for (int i=0; i<K; i++) {
		int miss = 0;
		
		cin >> name;
		
		vector<int> s = stock.at(name);
		
		for (int j=0; j<6; j++) {
			if (t.at(j) > s.at(j)) {
				miss += t.at(j)-s.at(j);
			}
		}
		
		cout << name << " ";
		if (miss == 0) {
			cout << "Successful";
		} else if (miss <= 2) {
			cout << "Mildly Successful (" << miss << ")";
		} else {
			cout << "Disaster (" << miss << ")";
		}
		cout << endl;
	}
	
	return 0;
}