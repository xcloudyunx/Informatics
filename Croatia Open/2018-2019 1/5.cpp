#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	char input[22];
	cin.getline(input, sizeof(input));
	int L, R, M; stringstream(input) >> L >> R >> M;
	
	int edges[M][3];
	for (int i=0; i<M; i++) {
		cin.getline(input, sizeof(input));
		stringstream(input) >> edges[i][0] >> edges[i][1];
	}
	
	int a[L+1][R];
	for (int i=0; i<L+1; i++) {
		for (int j=0; j<R; j++) {
			a[i][j] = M+1;
		}
	}
	int b[R+1][L];
	for (int i=0; i<R+1; i++) {
		for (int j=0; j<L; j++) {
			b[i][j] = M+1;
		}
	}
	int colour;
	int K = 0;
	
	for (int i=0; i<M; i++) {
		colour = 1;
		
		while (find(a[edges[i][0]], a[edges[i][0]]+R, colour) != a[edges[i][0]]+R) {
			colour++;
		}
		while (find(b[edges[i][0]], b[edges[i][0]]+L, colour) != b[edges[i][0]]+L) {
			colour++;
		}
		a[edges[i][0]][R-1] = colour;
		sort(a[edges[i][0]], a[edges[i][0]]+R);
		b[edges[i][0]][L-1] = colour;
		sort(b[edges[i][0]], b[edges[i][0]]+L);
		edges[i][2] = colour;
		
		K = max(K, colour);
	}
	
	cout << K << endl;
	for (int i=0; i<M; i++) {
		cout << edges[i][2] << endl;
	}
}