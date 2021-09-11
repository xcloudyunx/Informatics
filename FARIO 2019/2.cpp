#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, c, p, a, b;
	cin >> n >> c;
	
	vector<int> path(n);
	vector< vector<int> > cp(c);
	
	for (int i=0; i<n; i++) {
		cin >> a;
		a--;
		path.at(i) = a;
		cp.at(a).push_back(i);
	}
	
	/*for (auto i : path) {
		cout << i << " ";
	}
	cout << endl;
	cout << endl;*/
	
	cin >> p;
	
	vector< set<int> > colours(c);
	
	for (int i=0; i<p; i++) {
		cin >> a >> b;
		a--;
		b--;
		
		colours.at(a).insert(b);
		colours.at(b).insert(a);
	}
	
	/*for (auto i : cp) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	
	vector<int> ways(n, 0);
	ways.at(0) = 1;
	
	for (int i=0; i<n; i++) {
		if (ways.at(i) != 0) {
			for (auto k : colours.at(path.at(i))) {
				for (auto j : cp.at(k)) {
					if (j > i) {
						ways.at(j) = (ways.at(j)+ways.at(i))%1000000007;
					}
				}
			}
		}
	}
	
	/*for (auto i : ways) {
		cout << i << " ";
	}
	cout << endl;*/
	
	cout << ways.back() << endl;
	
	return 0;
}