#include <bits/stdc++.h>

using namespace std;

int main() {
	int X, W;
	cin >> X >> W;
	
	vector<int> scores(X);
	vector<int> maxyears(100001, INT_MAX);
	
	long long score = 0;
	
	for (int i=0; i<X; i++) {
		cin >> scores.at(i);
		score += scores.at(i);
	}
	
	int tmp;
	for (int i=0; i<W; i++) {
		cin >> tmp;
		
		if (maxyears.at(tmp) == INT_MAX) {
			int temp = 0;
			for (int j=0; j<tmp; j++) {
				temp += scores.at(j);
			}
			int cmax = max(temp, 0);
			for (int j=0; j<X-tmp; j++) {
				temp += scores.at(j+tmp)-scores.at(j);
				cmax = max(temp, cmax);
			}
			maxyears.at(tmp) = cmax;
		}
		
		score += maxyears.at(tmp);
	}
	
	cout << score << endl;
	
	return 0;
}