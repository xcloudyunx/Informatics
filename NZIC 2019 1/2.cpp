#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int total = 0;
	
	for (int i=1; i<N; i++) {
		total += 3*i;
	}
	
	total += 2*N;
	
	cout << total;
	
	return 0;
}