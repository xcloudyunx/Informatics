#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int z=1; z<=T; z++) {
		int N, Q;
		cin >> N >> Q;
		
		vector<bool> seats(N, false);
		vector< priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > > q(2); //size, start
		
		for (int i=0; i<Q; i++) {
			int l, r;
			cin >> l >> r;
			q.at(0).push(make_pair(r-l+1, l));
		}
		
		int K = 0;
		
		bool broken = false;
		
		for (int i=0; i<N; i++) {
			while (!q.at(i%2).empty()) {
				int size = q.at(i%2).top().first;
				int start = q.at(i%2).top().second;
				q.at(i%2).pop();
				
				while (start<N && seats.at(start) && size>0) {
					start++;
					size--;
				}
				if (size == 0 || start==N) {
					broken = true;
					break;
				}
				
				seats.at(start) = true;
				q.at((i+1)%2).push(make_pair(size, start));
			}
			if (broken) {
				break;
			}
			K++;
		}
		
		cout << "Case #" << z << ": " << K << endl;
	}
	
	return 0;
}