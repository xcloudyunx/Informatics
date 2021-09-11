#include <bits/stdc++.h>

using namespace std;

int main() {
	int S, N, H, T, X, Y, M;
	cin >> S;
	
	vector<int> songs(S);
	for (int i=0; i<S; i++) cin >> songs.at(i);
	
	cin >> N >> H >> T;
	H--;
	
	vector< vector< pair<int, int> > > adj(N); //dest, song
	for (int i=0; i<T; i++) {
		cin >> X >> Y >> M;
		X--;
		Y--;
		adj.at(X).push_back(make_pair(Y, M));
		adj.at(Y).push_back(make_pair(X, M));
	}
	
	vector< vector<int> > scores(2, vector<int> (N, INT_MAX/2));
	
	queue< pair<int, int> > q; //dest, song
	q.push(make_pair(H, 0));
	scores.at(1).at(H) = 0;
	
	int prevs = 0;
	while (!q.empty()) {
		int f = q.front().first;
		int s = q.front().second;
		q.pop();
		
		if (s == S) break;
		
		if (s != prevs) {
			/*for (auto i : scores.at(s%2)) {
				cout << i << " ";
			}
			cout << endl;*/
			scores.at(s%2).assign(N, INT_MAX/2);
			prevs = s;
		}
		
		int t = scores.at((s+1)%2).at(f);
		
		for (auto i : adj.at(f)) {
			if (i.second == songs.at(s)) {
				if (t < scores.at(s%2).at(i.first)) {
					q.push(make_pair(i.first, s+1));
					scores.at(s%2).at(i.first) = t;
				}
			} else {
				if (t+1 < scores.at(s%2).at(i.first)) {
					q.push(make_pair(i.first, s+1));
					scores.at(s%2).at(i.first) = t+1;
				}
			}
		}
	}
	
	/*for (auto i : scores.at((S+1)%2)) {
		cout << i << " ";
	}
	cout << endl;*/
	cout << scores.at((S+1)%2).at(H) << endl;
	
	return 0;
}