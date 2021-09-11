#include <bits/stdc++.h>

using namespace std;

int main() {
	int K, A, B;
	cin >> K >> A >> B;
	
	K += max(A, B);
	
	int x1 = K/4;
	int y1 = K/2-x1;

	K += min(A, B);
	
	int x2 = K/4;
	int y2 = K/2-x2;
	
	cout << max(x1*y1, x2*y2-A*B);
	
	return 0;
}