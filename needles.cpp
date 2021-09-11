#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &needles, int min, int max, int x) {
	while (min <= max) {
		int mid = (min+max)/2;
		if (x == needles.at(mid)) {
			return mid;
		} else if (x < needles.at(mid)) {
			max = mid-1;
		} else {
			min = mid+1;
		}
	}
	return 0;
}

int main() {
	int N;
	cin >> N;
	
	vector<int> needles(N+1);
	
	for (int i=1; i<=N; i++) {
		cin >> needles.at(i);
	}
	
	int x;
	cin >> x;
	while (x != -1) {
		int h = binarySearch(needles, 1, N, x);
		if (h == 0) {
			cout << "needle is gone forever" << endl;
		} else {
			cout << h << endl;
		}
		
		cin >> x;
	}
	
	return 0;
}