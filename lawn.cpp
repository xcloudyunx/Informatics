#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	vector<string> outputs;
	for (int z=0; z<T; z++) {
		int N, M;
		cin >> N >> M;
		cin.ignore();
		
		vector<vector<int>> lawn(N);
		vector<vector<int>> grid(N, vector<int>(M, 100));
		
		for (int i=0; i<N; i++) {
			char input[4*M];
			cin.getline(input, sizeof(input));
			stringstream ss(input);
			int a;
			while (ss >> a) {
				lawn.at(i).push_back(a);
			}
		}
		
		for (int i=0; i<N; i++) {
			int start = *max_element(lawn.at(i).begin(), lawn.at(i).end());
			grid.at(i).assign(M, start);
		}
		
		for (int i=0; i<M; i++) {
			int start = lawn.at(0).at(i);
			for (int j=1; j<N; j++) {
				start = max(start, lawn.at(j).at(i));
			}
			for (int j=0; j<N; j++) {
				if (start < grid.at(j).at(i)) {
					grid.at(j).at(i) = start;
				}
			}
		}
		
		/*for (vector<int> row : grid) {
			for (int col : row) {
				cout << col << " ";
			}
			cout << endl;
		}*/
		
		if (grid == lawn) {
			outputs.push_back("YES");
		} else {
			outputs.push_back("NO");
		}
	}
	
	for (int i=0; i<T; i++) {
		cout << "Case #" << i+1 << ": " << outputs.at(i) << endl;
	}
	
	return 0;
}