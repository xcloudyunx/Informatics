#include <bits/stdc++.h>

using namespace std;

int orientation(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	return (p2.second-p1.second)*(p3.first-p2.first) - (p3.second-p2.second)*(p2.first-p1.first);
}

int main() {
	int T;
	cin >> T;
	
	for (int z=0; z<T; z++) {
		int N;
		cin >> N;
		
		if (N == 1) {
			cout << 1 << endl;
			continue;
		}
		
		vector< pair<int, int> > P(N);
		
		for (int i=0; i<N; i++) {
			cin >> P.at(i).first >> P.at(i).second;
		}
		
		sort(P.begin(), P.end());
		
		for (int i=N-1; i>0; i--) {
			if (P.at(i) == P.at(i-1)) {
				P.erase(P.begin()+i);
			}
		}
		
		if (P.size() == 1) {
			cout << 1 << endl;
			continue;
		} else if (P.size() == 2) {
			cout << 2 << endl;
			continue;
		}
		
		vector< pair<int, int> > U, L;
		
		for (int i=0; i<P.size(); i++) {
			while (L.size() >= 2 && orientation(L.at(L.size()-2), L.back(), P.at(i)) <= 0) {
				L.pop_back();
			}
			L.push_back(P.at(i));
		}
		
		for (int i=P.size()-1; i>=0; i--) {
			while (U.size() >= 2 && orientation(U.at(U.size()-2), U.back(), P.at(i)) <= 0) {
				U.pop_back();
			}
			U.push_back(P.at(i));
		}
		
		L.pop_back();
		U.pop_back();
		
		/*for (auto i : L) {
			cout << i.first << " " << i.second << ", ";
		}
		cout << " ";
		for (auto i : U) {
			cout << i.first << " " << i.second << ", ";
		}
		cout << endl;*/
		
		cout << L.size()+U.size() << endl;
	}
	
	return 0;
}