#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
	int N, M, num = 0;
	cin >> N >> M;
	
	vector<string> grid(N);
	for (int i=0; i<N; i++) cin >> grid[i];
	vector<bool> line(N, false);
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (grid[i][j] == '*') {
				if (!line[j] && (!j || !line[j-1])) {
					num++;
				}
				line[j] = true;
			} else {
				line[j] = false;
			}
		}
	}
	
	cout << num << "\n";
	
	return 0;
}