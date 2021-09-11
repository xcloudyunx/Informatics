#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;
	
	vector< pair<int, int> > options(N); //profit, complaint
	
	int p, c, a;
	cin >> p >> c;
	options.at(0) = {p, c};
	
	for (int i=1; i<N; i++) {
		cin >> p >> c >> a;
		a--;
		options.at(i) = {options.at(a).first+p, options.at(a).second+c};
	}
	
	vector<int> table(C+1, 0);
	
	for (int i=0; i<=C; i++) {
		for (int j=0; j<N; j++) {
			if (options.at(j).second <= i)
				table.at(i) = max(table.at(i), table.at(i-options.at(j).second)+options.at(j).first);
		}
	}
	
	cout << table.back() << endl;
	
	return 0;
}