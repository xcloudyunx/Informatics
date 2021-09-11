#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int P, D;
	cin >> P >> D;
	
	while (P && D) {
		vector< pair<float, float> > pads(P);
		for (int i=0; i<P; i++) {
			cin >> pads[i].first >> pads[i].second;
		}
		vector< vector<float> > distances(P, vector<float>(P, 0));
		for (int i=0; i<P; i++) {
			for (int j=i+1; j<P; j++) {
				distances[i][j] = sqrt((pads[i].first-pads[j].first)*(pads[i].first-pads[j].first) + (pads[i].second-pads[j].second)*(pads[i].second-pads[j].second));
				distances[j][i] = distances[i][j];
			}
		}
		
		/*for (auto i : distances) {
			for (auto j : i) cout << j << " ";
			cout << endl;
		}
		cout << endl;*/
		
		vector< pair<int, float> > v(P, {-1, 0}); //num of jumps, distance
		queue<ii> q; //current jump, node
		q.push({0, 0});
		v[0] = {0, INF};
		
		while (!q.empty()) {
			int j = q.front().first;
			int f = q.front().second;
			q.pop();
			//cout << j << " " << f << endl;
			for (int i=0; i<P; i++) {
				if (distances[i][f] <= D) {
					float x = min(distances[i][f], v[f].second);
					if (v[i].first < 0 || j+1 < v[i].first || (j+1 == v[i].first && v[i].second < x)) {
						v[i] = {j+1, x};
						//cout << "D: " << v[i].first << " " << v[i].second << "\n";
						q.push({j+1, i});
					}
				}
			}
		}
		printf("%d %.1f\n", v[1].first, v[1].second);
		//cout << v[1].first << " " << v[1].second << "\n";
		
		cin >> P >> D;
	}
}