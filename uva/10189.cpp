#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n;
	string s;
	cin >> n >> m;
	int TC = 1;
	while (m || n) {
		vector< vector<char> > field(n, vector<char>(m, '0'));
		for (int i=0; i<n; i++) {
			cin >> s;
			for (int j=0; j<m; j++) {
				if (s.at(j) == '*') {
					field.at(i).at(j) = '*';
					if (i > 0) {
						if (j > 0) {
							if (field.at(i-1).at(j-1) != '*') {
								field.at(i-1).at(j-1) = ((field.at(i-1).at(j-1)-'0')+1)+'0';
							}
						}
						if (j < m-1) {
							if (field.at(i-1).at(j+1) != '*') {
								field.at(i-1).at(j+1) = ((field.at(i-1).at(j+1)-'0')+1)+'0';
							}
						}
						if (field.at(i-1).at(j) != '*') {
							field.at(i-1).at(j) = ((field.at(i-1).at(j)-'0')+1)+'0';
						}
					}
					if (i < n-1) {
						if (j > 0) {
							if (field.at(i+1).at(j-1) != '*') {
								field.at(i+1).at(j-1) = ((field.at(i+1).at(j-1)-'0')+1)+'0';
							}
						}
						if (j < m-1) {
							if (field.at(i+1).at(j+1) != '*') {
								field.at(i+1).at(j+1) = ((field.at(i+1).at(j+1)-'0')+1)+'0';
							}
						}
						if (field.at(i+1).at(j) != '*') {
							field.at(i+1).at(j) = ((field.at(i+1).at(j)-'0')+1)+'0';
						}
					}
					if (j > 0) {
						if (field.at(i).at(j-1) != '*') {
							field.at(i).at(j-1) = ((field.at(i).at(j-1)-'0')+1)+'0';
						}
					}
					if (j < m-1) {
						if (field.at(i).at(j+1) != '*') {
							field.at(i).at(j+1) = ((field.at(i).at(j+1)-'0')+1)+'0';
						}
					}
				}
			}
		}
		
		cout << "Field #" << TC << ": \n";
		for (auto i : field) {
			for (auto j : i) {
				cout << j;
			}
			cout << "\n";
		}
		cout << "\n";
		
		TC++;
		cin >> n >> m;
	}
	
	return 0;
}