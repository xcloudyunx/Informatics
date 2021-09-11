#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	int score, frame, i;
	while (s != "Game Over") {
		score = 0;
		frame = 1;
		i = 0;
		while (frame <= 10) {
			if (s.at(i) != 'X') {
				if (s.at(i+2) != '/') {
					score += (s.at(i)-'0') + (s.at(i+2)-'0');
				} else {
					score += 10;
					if (s.at(i+4) != 'X') {
						score += (s.at(i+4)-'0');
					} else {
						score += 10;
					}
				}
				i += 4;
			} else {
				score += 10;
				if (s.at(i+2) != 'X') {
					if (s.at(i+4) != '/') {
						score += (s.at(i+2)-'0') + (s.at(i+4)-'0');
					} else {
						score += 10;
					}
				} else {
					if (s.at(i+4) != 'X') {
						score += 10 + (s.at(i+4)-'0');
					} else {
						score += 20;
					}
				}
				i += 2;
			}
			frame++;
		}
		
		cout << score << "\n";
		
		getline(cin, s);
	}
	
	return 0;
}