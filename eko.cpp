#include <bits/stdc++.h>

using namespace std;

long long binarySearch(vector<long long> heights, long long M) {
	long long x;
	long long size = 500000000;
	long long height = 500000000;
	unordered_set<long long> v;
	while (true) {
		//cout << height << endl;
		x = 0;
		for (auto i : heights) {
			if (i > height) {
				x += i-height;
			}
		}
		if (x == M) {
			return height;
		} else if (size == 1) {
			if (x < M) {
				if (v.find(height-1) == v.end()) {
					height--;
				} else {
					return height-1;
				}
			} else {
				if (v.find(height+1) == v.end()) {
					height++;
				} else {
					return height;
				}
			}
			v.insert(height);
		} else {
			if (x < M) {
				size /= 2;
				height -= size;
			} else {
				size /=2;
				height += size;
			}
		}
	}
}

int main() {
	long long N, M;
	cin >> N >> M;
	
	vector<long long> heights(N);
	
	for (long long i=0; i<N; i++) {
		cin >> heights.at(i);
	}
	
	cout << binarySearch(heights, M) << endl;
	
	return 0;
}