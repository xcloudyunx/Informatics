#include <iostream>
#include <sstream>

using namespace std;

int factorial(int x) {
	int total = 1;
	for (int i=1; i<=x; i++) {
		total *= i;
	}
	return total;
}

int C(int n, int r) {
	return factorial(n)/(factorial(r)*factorial(n-r));
}

int main() {
	char input[10];
	cin.getline(input, sizeof(input));
	int N, M; stringstream(input) >> N >> M;
	
	char grid[N];
	for (int i=0; i<N; i++) {
		cin >> grid[i];
	}
	
	int values[N][M];
	for (int i=0; i<N; i++) {
		for (int j=0; j<M, j++) {
			values[i][j] = 0;
		}
	}
	
	int total = 0;
	
	M*N + (M-1)*N*2 + ...
	
	cout << total;
}