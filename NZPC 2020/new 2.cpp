#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<vvvc> vvvvc;
typedef vector<vvvvc> vvvvvc;
typedef vector<vvvvvc> vvvvvvc;
typedef vector<vvvvvvc> vvvvvvvc;

int main() {
	int N, X, O;
	string tmp;
	string s;
	cin >> N;
	while (N) {
		s = ""
		X = 0, O = 0;
		cin.ignore();
		while (s.size() != pow(3, N)){
			getline(cin, tmp);
			s += tmp;
		}
		if (N == 1) {
			vc grid(3);
			for (int a=0; a<3; a++) {
				grid[a] = s[a];
			}
			if (grid[0] == grid[1] && grid[0] == grid[2] && grid[0] != '~') {
				if (grid[0] == 'X') X++;
				else O++;
			}
		} else if (N == 2) {
			vvc grid(3, vc(3));
			for (int a=0; a<3; a++) {
				for (int b=0; b<3; b++) {
					grid[a][b] = s[a*3+b];
				}
			}
			for ()
		}
		
		cin >> N;
	}
}