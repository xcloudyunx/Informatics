#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int z=1; z<=T; z++) {
		int W, H, B;
		cin >> W >> H >> B;
		
		vector< tuple<int, int, int, int> > g(B);
		
		for (int i=0; i<B; i++) {
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			g.at(i) = make_tuple(x0, y0, x1, y1);
		}
		
		for (auto i : v) {
			cout << i << endl;
		}
		
		cout << "Case #" << z << ": " << *min_element(v.begin(), v.end()) << endl;
	}
	
	return 0;
}