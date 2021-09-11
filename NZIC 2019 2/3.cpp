#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int one = -1;
	int two = -1;
	int three = -1;
	bool fault = false;
	
	for (int i=0; i<N; i++) {
		int q;
		cin >> q;
		if (!fault && q < K) {
			if (one != -1) {
				if (two != -1) {
					three = q;
					fault = true;
				} else {
					two = q;
				}
			} else {
				one = q;
			}
		} else if (!fault) {
			one = -1;
			two = -1;
			three = -1;
		}
	}
	
	if (fault) {
		cout << "Fault Detected" << endl;
		cout << one << " " << two << " " << three << endl;
	} else {
		cout << "No Fault" << endl;
	}
	
	return 0;
}