#include <bits/stdc++.h>

using namespace std;

int main() {
	int L, N, x, v;
	cin >> L >> N;
	
	priority_queue< vector<int>, vector< vector<int> >, greater< vector<int> > > q; //cpos, start=0/end=1, screen
	
	vector< pair<int, int> > screens(N); //pos, angle
	vector<int> occur(N, 0);
	
	for (int i=0; i<N; i++) {
		cin >> x >> v;
		screens.at(i) = make_pair(x, v);
		q.push({max(0, x-v), 0, i});
		q.push({min(L, x+v), 1, i});
	}
	
	priority_queue< vector<int>, vector< vector<int> >, greater< vector<int> > > order; //angle, pos, screen
	vector<bool> available(N, true);
	
	while (!q.empty()) {
		int cpos = q.top().at(0);
		while (!q.empty() && q.top().at(0) == cpos) {
			int pos = q.top().at(0);
			int end = q.top().at(1);
			int screen = q.top().at(2);
			q.pop();
			
			if (end) {
				available.at(screen) = false;
			} else {
				order.push({screens.at(screen).second, screens.at(screen).first, screen});
			}
		}
		
		while (!order.empty() && !available.at(order.top().at(2))) {
			order.pop();
		}
		if (!order.empty()) {
			occur.at(order.top().at(2)) += q.top().at(0)-cpos;
		}
	}
	
	for (auto i : occur) {
		cout << i << "\n";
	}
	
	return 0;
}