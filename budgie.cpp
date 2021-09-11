#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, a, b;
	cin >> N;
	
	priority_queue< tuple<int, int, int> > q; //time, start/end, budgie
	//bitset<100001> taken;
	bitset<100001> current;
	int total = 0;
	
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		q.push(make_tuple(a, 0, i));
		q.push(make_tuple(b, 1, i));
	}
	
	while (!q.empty()) {
		int f = get<0>(q.top());
		int se = get<1>(q.top());
		int b = get<2>(q.top());
		q.pop();
		
		if (current.test(b)) {
			current.reset();
			total++;
			//cout << f << endl;
		} else {
			current.flip(b);
		}
	}
	
	cout << total << endl;
}