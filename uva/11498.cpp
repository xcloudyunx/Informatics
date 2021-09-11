#include <bits/stdc++.h>

using namespace std;

int main() {
	int K, N, M, X, Y;
	cin >> K;

	while (K != 0) {
		cin >> N >> M;
	
		while (K--) {
			cin >> X >> Y;
			if (X == N || Y == M) {
				cout << "divisa\n";
			} else if (X < N && Y > M) {
				cout << "NO\n";
			} else if (X > N && Y > M) {
				cout << "NE\n";
			} else if (X > N && Y < M) {
				cout << "SE\n";
			} else if (X < N && Y < M) {
				cout << "SO\n";
			}
		}
		
		cin >> K;
	}
	
	return 0;
}