#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> numbers, int high, int x) {
	int low = 0;
	
	while (low <= high) {
		int mid = (low+high)/2;
		if (numbers.at(mid) == x) {
			return mid;
		} else if (numbers.at(mid) > x) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	
	return -1;
}

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> numbers(N);
	
	for (int i=0; i<N; i++) {
		cin >> numbers.at(i);
	}
	
	for (int i=0; i<K; i++) {
		int F;
		cin >> F;
		cout << binarySearch(numbers, N-1, F) << endl;
	}
	
	return 0;
}