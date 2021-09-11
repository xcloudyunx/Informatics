#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, A, B, C;
	cin >> N >> A >> B >> C;
	
	vector<int> nums;
	
	if (A == B && B == C) {
		for (int i=0; i<N; i++) {
			nums.push_back(A);
		}
	} else if (N == 1) {
		
	} else if (N == 3) {
		int x = A*N-(N-1)*B;
		if (B == C && x > 0 && x <= 1000000) {
			nums.push_back(x);
			for (int i=1; i<N; i++) {
				nums.push_back(B);
			}
		}
	} else if (B == C) {
		int x = A*N-(N-1)*B;
		
		if (x > 0 && x <= 1000000) {
			nums.push_back(x);
			for (int i=1; i<N; i++) {
				nums.push_back(B);
			}
		} else {
			nums.push_back(B);
			nums.push_back(B);
			x = A*N-2*B;
			x1 = x/(N-2);
			for (int i=1; i<(N-2)/2; i++) {
				if (x1+i && x1-i)
				nums.push_back(x1+i);
				nums.push_back(x1-i);
			}
		}
	}
	
	if (!nums.empty()) {
		cout << "Possible" << endl;
		for (auto i : nums) {
			cout << i << " ";
		}
	} else {
		cout << "Impossible";
	}
	
	return 0;
}