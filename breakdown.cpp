#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;
	
	vector<int> T;
	for (int i=0; i<N; i++) {
		int x;
		cin >> x;
		T.push_back(x);
	}
	
	sort(T.begin(), T.end());
	
	vector<int> outputs;
	for (int i=0; i<C; i++) {
		int x;
		cin >> x;
		int difference = abs(T.front()-x);
		int position = 0;
		for (int j=1; j<N; j++) {
			int x = abs(T.at(i)-x);
			cout << difference << " " << x << endl;
			if (x < difference) {
				difference = x;
				position = i;
			} else {
				break;
			}
		}
		outputs.push_back(T.at(i));
	}
	
	for (int i : outputs) {
		cout << i << endl;
	}
	
	return 0;
}