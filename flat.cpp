#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, H;
	cin >> N >> H;
	
	vector< pair<int, int> > boxes(N);
	
	for (int i=0; i<N; i++) {
		cin >> boxes.at(i).first;
		cin >> boxes.at(i).second;
	}
	
	vector< vector<int> > table(2*N+2, vector<int> (H+1, 0));
	
	for (int i=2; i<=N+1; i++) {
		for (int j=1; j<=H; j++) {
			if (boxes.at(i-2).first <= j) {
				table.at(2*i-2).at(j) = max(boxes.at(i-2).first+max(table.at(2*i-3).at(j-boxes.at(i-2).first), table.at(2*i-4).at(j-boxes.at(i-2).first)), max(table.at(2*i-3).at(j), table.at(2*i-4).at(j)));
			} else {
				table.at(2*i-2).at(j) = max(table.at(2*i-3).at(j), table.at(2*i-4).at(j));
			}
			if (boxes.at(i-2).second <= j) {
				table.at(2*i-1).at(j) = max(boxes.at(i-2).second+max(table.at(2*i-3).at(j-boxes.at(i-2).second), table.at(2*i-4).at(j-boxes.at(i-2).second)), max(table.at(2*i-3).at(j), table.at(2*i-4).at(j)));
			} else {
				table.at(2*i-1).at(j) = max(table.at(2*i-3).at(j), table.at(2*i-4).at(j));
			}
		}
	}
	
	/*for (auto i : table) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}*/
	
	cout << max(table.at(2*N+1).at(H), table.at(2*N).at(H)) << endl;
	
	return 0;
}