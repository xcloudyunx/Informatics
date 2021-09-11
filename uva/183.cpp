#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

string dac(int r1, int r2, int c1, int c2, vector< vector<char> > &grid) {
	if (r1 == r2 && c1 == c2) return string(1, grid[r1][c1]);
	if (r1 == r2) {
		string r = dac(r1, r2, 1+(c1+c2)/2, c2, grid);
		string l = dac(r1, r2, c1, (c1+c2)/2, grid);
		if (l.size() == 1 && l == r) return l;
		else return "D"+l+r;
	} else if (c1 == c2) {
		string b = dac(1+(r1+r2)/2, r2, c1, c2, grid);
		string t = dac(r1, (r1+r2)/2, c1, c2, grid);
		if (t.size() == 1 && t == b) return t;
		else return "D"+t+b;
	} else {
		string br = dac(1+(r1+r2)/2, r2, 1+(c1+c2)/2, c2, grid);
		string bl = dac(1+(r1+r2)/2, r2, c1, (c1+c2)/2, grid);
		string tr = dac(r1, (r1+r2)/2, 1+(c1+c2)/2, c2, grid);
		string tl = dac(r1, (r1+r2)/2, c1, (c1+c2)/2, grid);
		if (tl.size() == 1 && tl == tr && tl == bl && tl == br) return tl;
		else {
			return "D"+tl+tr+bl+br;
		}
	}
}

void dac2(int r1, int r2, int c1, int c2, vector< vector<char> > &grid, string &s, int &i) {
	int x = i;
	if (r1 == r2 && c1 == c2) grid[r1][c1] = s[i];
	else if (r1 == r2) {
		if (s[x] == 'D') {
			dac2(r1, r2, c1, (c1+c2)/2, grid, s, ++i);
			dac2(r1, r2, 1+(c1+c2)/2, c2, grid, s, ++i);
		} else {
			for (int c=c1; c<=c2; c++) grid[r1][c] = s[i];
		}
	} else if (c1 == c2) {
		if (s[x] == 'D') {
			dac2(r1, (r1+r2)/2, c1, c2, grid, s, ++i);
			dac2(1+(r1+r2)/2, r2, c1, c2, grid, s, ++i);
		} else {
			for (int r=r1; r<=r2; r++) grid[r][c1] = s[i];
		}
	} else {
		if (s[x] == 'D') {
			dac2(r1, (r1+r2)/2, c1, (c1+c2)/2, grid, s, ++i);
			dac2(r1, (r1+r2)/2, 1+(c1+c2)/2, c2, grid, s, ++i);
			dac2(1+(r1+r2)/2, r2, c1, (c1+c2)/2, grid, s, ++i);
			dac2(1+(r1+r2)/2, r2, 1+(c1+c2)/2, c2, grid, s, ++i);
		} else {
			for (int r=r1; r<=r2; r++) {
				for (int c=c1; c<=c2; c++) grid[r][c] = s[i];
			}
		}
	}
}

int main() {
	char f;
	int r, c;
	string s, tmp;
	cin >> f;
	while (f != '#') {
		cin >> r >> c;
		s = "";
		while (s.size() < r*c) {
			cin >> tmp;
			s += tmp;
		}
		
		vector< vector<char> > grid(r, vector<char>(c));
		if (f == 'B') {
			for (int i=0; i<r; i++) {
				for (int j=0; j<c; j++) {
					grid[i][j] = s[i*c+j];
				}
			}
			printf("D% 4d% 4d", r, c);
			s = dac(0, r-1, 0, c-1, grid);
			for (int i=0; i<s.size(); i++) {
				if (i%50 == 0) cout << "\n";
				cout << s[i];
			}
			cout << "\n";
		} else {
			printf("B% 4d% 4d", r, c);
			int x = 0;
			dac2(0, r-1, 0, c-1, grid, s, x);
			for (int i=0; i<r; i++) {
				for (int j=0; j<c; j++) {
					if ((i*c+j)%50 == 0) cout << "\n";
					cout << grid[i][j];
				}
			}
			cout << "\n";
		}
		
		
		cin >> f;
	}
	
	return 0;
}
