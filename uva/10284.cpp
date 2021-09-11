#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	int x, y, total;
	while (cin >> s) {
		vector< vector<char> > board(8, vector<char>(8, '0'));
		total = 0;
		x = 0;
		y = 0;
		for (auto c : s) {
			if (c == 'p') {
				board.at(x).at(y) = 'p'; //black goes left
				x++;
			} else if (c == 'P') {
				board.at(x).at(y) = 'P'; //white goes right
				x++;
			} else if (c == 'n' || c == 'N') {
				board.at(x).at(y) = 'n';
				x++;
			} else if (c == 'b' || c == 'B') {
				board.at(x).at(y) = 'b';
				x++;
			} else if (c == 'r' || c == 'R') {
				board.at(x).at(y) = 'r';
				x++;
			} else if (c == 'q' || c == 'Q') {
				board.at(x).at(y) = 'q';
				x++;
			} else if (c == 'k' || c == 'K') {
				board.at(x).at(y) = 'k';
				x++;
			} else if (c == '/') {
				y++;
				x = 0;
			} else {
				x += c-'0';
			}
		}

		for (int i=0; i<8; i++) {
			for (int j=0; j<8; j++) {
				if (board.at(i).at(j) == 'p') {
					if (j < 7 && i > 0) {
						if (board.at(i-1).at(j+1) == '0') {
							board.at(i-1).at(j+1) = '1';
						}
					}
					if (j < 7 && i < 7) {
						if (board.at(i+1).at(j+1) == '0') {
							board.at(i+1).at(j+1) = '1';
						}
					}
				} else if (board.at(i).at(j) == 'P') {
					if (j > 0 && i > 0) {
						if (board.at(i-1).at(j-1) == '0') {
							board.at(i-1).at(j-1) = '1';
						}
					}
					if (j > 0 && i < 7) {
						if (board.at(i+1).at(j-1) == '0') {
							board.at(i+1).at(j-1) = '1';
						}
					}
				} else if (board.at(i).at(j) == 'n') {
					if (j > 0 && i > 1) {
						if (board.at(i-2).at(j-1) == '0') {
							board.at(i-2).at(j-1) = '1';
						}
					}
					if (j > 1 && i > 0) {
						if (board.at(i-1).at(j-2) == '0') {
							board.at(i-1).at(j-2) = '1';
						}
					}
					if (j < 7 && i < 6) {
						if (board.at(i+2).at(j+1) == '0') {
							board.at(i+2).at(j+1) = '1';
						}
					}
					if (j < 6 && i < 7) {
						if (board.at(i+1).at(j+2) == '0') {
							board.at(i+1).at(j+2) = '1';
						}
					}
					if (j > 0 && i < 6) {
						if (board.at(i+2).at(j-1) == '0') {
							board.at(i+2).at(j-1) = '1';
						}
					}
					if (j > 1 && i < 7) {
						if (board.at(i+1).at(j-2) == '0') {
							board.at(i+1).at(j-2) = '1';
						}
					}
					if (j < 7 && i > 1) {
						if (board.at(i-2).at(j+1) == '0') {
							board.at(i-2).at(j+1) = '1';
						}
					}
					if (j < 6 && i > 0) {
						if (board.at(i-1).at(j+2) == '0') {
							board.at(i-1).at(j+2) = '1';
						}
					}
				} else if (board.at(i).at(j) == 'b') {
					x = i+1;
					y = j+1;
					while (x < 8 && y < 8) {
						if (board.at(x).at(y) == '0' || board.at(x).at(y) == '1') {
							board.at(x).at(y) = '1';
							x++;
							y++;
						} else {
							break;
						}
					}
					x = i-1;
					y = j-1;
					while (x >= 0 && y >= 0) {
						if (board.at(x).at(y) == '0' || board.at(x).at(y) == '1') {
							board.at(x).at(y) = '1';
							x--;
							y--;
						} else {
							break;
						}
					}
					x = i+1;
					y = j-1;
					while (x < 8 && y >= 0) {
						if (board.at(x).at(y) == '0' || board.at(x).at(y) == '1') {
							board.at(x).at(y) = '1';
							x++;
							y--;
						} else {
							break;
						}
					}
					x = i-1;
					y = j+1;
					while (x >= 0 && y < 8) {
						if (board.at(x).at(y) == '0' || board.at(x).at(y) == '1') {
							board.at(x).at(y) = '1';
							x--;
							y++;
						} else {
							break;
						}
					}
				} else if (board.at(i).at(j) == 'r') {
					x = i+1;
					while (x < 8) {
						if (board.at(x).at(j) == '0' || board.at(x).at(j) == '1') {
							board.at(x).at(j) = '1';
							x++;
						} else {
							break;
						}
					}
					x = i-1;
					while (x >= 0) {
						if (board.at(x).at(j) == '0' || board.at(x).at(j) == '1') {
							board.at(x).at(j) = '1';
							x--;
						} else {
							break;
						}
					}
					y = j-1;
					while (y >= 0) {
						if (board.at(i).at(y) == '0' || board.at(i).at(y) == '1') {
							board.at(i).at(y) = '1';
							y--;
						} else {
							break;
						}
					}
					y = j+1;
					while (y < 8) {
						if (board.at(i).at(y) == '0' || board.at(i).at(y) == '1') {
							board.at(i).at(y) = '1';
							y++;
						} else {
							break;
						}
					}
				} else if (board.at(i).at(j) == 'q') {
					x = i+1;
					y = j+1;
					while (x < 8 && y < 8) {
						if (board.at(x).at(y) == '0' || board.at(x).at(y) == '1') {
							board.at(x).at(y) = '1';
							x++;
							y++;
						} else {
							break;
						}
					}
					x = i-1;
					y = j-1;
					while (x >= 0 && y >= 0) {
						if (board.at(x).at(y) == '0' || board.at(x).at(y) == '1') {
							board.at(x).at(y) = '1';
							x--;
							y--;
						} else {
							break;
						}
					}
					x = i+1;
					y = j-1;
					while (x < 8 && y >= 0) {
						if (board.at(x).at(y) == '0' || board.at(x).at(y) == '1') {
							board.at(x).at(y) = '1';
							x++;
							y--;
						} else {
							break;
						}
					}
					x = i-1;
					y = j+1;
					while (x >= 0 && y < 8) {
						if (board.at(x).at(y) == '0' || board.at(x).at(y) == '1') {
							board.at(x).at(y) = '1';
							x--;
							y++;
						} else {
							break;
						}
					}
					x = i+1;
					while (x < 8) {
						if (board.at(x).at(j) == '0' || board.at(x).at(j) == '1') {
							board.at(x).at(j) = '1';
							x++;
						} else {
							break;
						}
					}
					x = i-1;
					while (x >= 0) {
						if (board.at(x).at(j) == '0' || board.at(x).at(j) == '1') {
							board.at(x).at(j) = '1';
							x--;
						} else {
							break;
						}
					}
					y = j-1;
					while (y >= 0) {
						if (board.at(i).at(y) == '0' || board.at(i).at(y) == '1') {
							board.at(i).at(y) = '1';
							y--;
						} else {
							break;
						}
					}
					y = j+1;
					while (y < 8) {
						if (board.at(i).at(y) == '0' || board.at(i).at(y) == '1') {
							board.at(i).at(y) = '1';
							y++;
						} else {
							break;
						}
					}
				}  else if (board.at(i).at(j) == 'k') {
					if (i < 7 && j < 7) {
						if (board.at(i+1).at(j+1) == '0') {
							board.at(i+1).at(j+1) = '1';
						}
					}
					if (i > 0 && j > 0) {
						if (board.at(i-1).at(j-1) == '0') {
							board.at(i-1).at(j-1) = '1';
						}
					}
					if (i < 7 && j > 0) {
						if (board.at(i+1).at(j-1) == '0') {
							board.at(i+1).at(j-1) = '1';
						}
					}
					if (i > 0 && j < 7) {
						if (board.at(i-1).at(j+1) == '0') {
							board.at(i-1).at(j+1) = '1';
						}
					}
					if (i < 7) {
						if (board.at(i+1).at(j) == '0') {
							board.at(i+1).at(j) = '1';
						}
					}
					if (i > 0) {
						if (board.at(i-1).at(j) == '0') {
							board.at(i-1).at(j) = '1';
						}
					}
					if (j > 0) {
						if (board.at(i).at(j-1) == '0') {
							board.at(i).at(j-1) = '1';
						}
					}
					if (j < 7) {
						if (board.at(i).at(j+1) == '0') {
							board.at(i).at(j+1) = '1';
						}
					}
				}
			}
		}

		for (auto i : board) {
			for (auto j : i) {
				//cout << j << " ";
				if (j == '0') {
					total++;
				}
			}
			//cout << endl;
		}
		
		cout << total << "\n";
	}
	
	return 0;
}