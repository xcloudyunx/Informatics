#include <bits/stdc++.h>

using namespace std;

int main() {
	int w, h, k;
	cin >> w >> h >> k;
	
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q; //x, start
	
	for (int i=0; i<k; i++) {
		int p;
		cin >> p;
		int minx = w;
		int maxx = 0;
		for (int j=0; j<p; j++) {
			int x, y;
			cin >> x >> y;
			minx = min(minx, x);
			maxx = max(maxx, x);
		}
		q.push(make_pair(minx, 1));
		q.push(make_pair(maxx, -1));
	}
	
	int prevx = 0;
	int counter = 0;
	int total = 0;
	
	while (!q.empty()) {
		int f = q.top().first;
		int c = q.top().second;
		q.pop();
		
		if (counter == 0) {
			total += f-prevx;
		}
		prevx = f;
		counter += c;
	}
	total += w-prevx;
	
	cout << total << endl;
	
	return 0;
}