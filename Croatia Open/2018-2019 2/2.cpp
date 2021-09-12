#include <iostream>
#include <sstream>

using namespace std;

int main() {
	char input[7];
	cin.getline(input, sizeof(input));
	int N; stringstream(input) >> N;
	
	char input1[9*N];
	int x;
	
	cin.getline(input1, sizeof(input1));
	int L[N];
	int q = 0;
	stringstream a(input1);
	while (a >> x) {
		L[q] = x;
		q++;
	}
	
	cin.getline(input1, sizeof(input1));
	int R[N];
	q = 0;
	stringstream b(input1);
	while (b >> x) {
		R[q] = x;
		q++;
	}
	
	cin.getline(input1, sizeof(input1));
	int U[N];
	q = 0;
	stringstream c(input1);
	while (c >> x) {
		U[q] = x;
		q++;
	}
	
	cin.getline(input1, sizeof(input1));
	int D[N];
	q = 0;
	stringstream d(input1);
	while (d >> x) {
		D[q] = x;
		q++;
	}
	
	int square[N*N];
	for (int i=0; i<N*N; i++) {
		square[i] = 0;
	}
	
	for (int i=0; i<N; i++) {
		if (L[i] > -1) {
			if (square[L[i] + i*N ] == 0)
				square[L[i] + i*N ] = 1;
			else if (square[L[i] + i*N ] == -1) {
				cout << "NE";
				return 0;
			}
		} else if (L[i] == -1) {
			for (int j=0; j<N; j++) {
				if (square[j + i*N] == 0) {
					square[j + i*N] = -1;
				} else if (square[j + i*N] == 1) {
					cout << "NE";
					return 0;
				}
			}
		}
		
		if (R[i] > -1) {
			if (square[(N-R[i]-1) + i*N] == 0)
				square[(N-R[i]-1) + i*N] = 1;
			else if (square[(N-R[i]-1) + i*N] == -1) {
				cout << "NE";
				return 0;
			}
		} else if (R[i] == -1) {
			for (int j=1; j<N+1; j++) {
				if (square[(N-j) + i*N] == 0) {
					square[(N-j) + i*N] = -1;
				} else if (square[(N-j) + i*N] == 1) {
					cout << "NE";
					return 0;
				}
			}
		}
		
		if (U[i] > -1) {
			if (square[i + U[i]*N] == 0)
				square[i + U[i]*N] = 1;
			else if (square[i + U[i]*N] == -1) {
				cout << "NE";
				return 0;
			}
		} else if (U[i] == -1) {
			for (int j=0; j<N; j++) {
				if (square[i + j*N] == 0) {
					square[i + j*N] = -1;
				} else if (square[i + j*N] == 1) {
					cout << "NE";
					return 0;
				}
			}
		}
		
		if (D[i] > -1) {
			if (square[i + (N-D[i]-1)*N] == 0)
				square[i + (N-D[i]-1)*N] = 1;
			else if (square[i + (N-D[i]-1)*N] == -1) {
				cout << "NE";
				return 0;
			}
		} else if (D[i] == -1) {
			for (int j=1; j<N+1; j++) {
				if (square[i + (N-j)*N] == 0) {
					square[i + (N-j)*N] = -1;
				} else if (square[i + (N-j)*N] == 1) {
					cout << "NE";
					return 0;
				}
			}
		}
	}
	
	cout << "DA";
	return 0;
}