#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int x;
	vector<int> pages;
	for (int i=0; i<N; i++) {
		cin >> x;
		pages.push_back(x);
	}
	
	vector<int> K = {};
	for (int i : pages) {
		auto it = upper_bound(K.begin(), K.end(), i);
		if (it == K.end()) {
			K.push_back(i);
		} else {
			K.at(distance(K.begin(), it)) = i;
		}
	}
	
	cout << K.size();
	
	return 0;
}