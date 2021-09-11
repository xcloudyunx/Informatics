#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<string> hand(13);
	while (cin >> hand.at(0) >> hand.at(1) >> hand.at(2) >> hand.at(3) >> hand.at(4) >> hand.at(5) >> hand.at(6) >> hand.at(7) >> hand.at(8) >> hand.at(9) >> hand.at(10) >> hand.at(11) >> hand.at(12)) {
		unordered_map<char, pair<int, vector<bool> > > suits = {{'S', {0, vector<bool>(4, false)}}, {'H', {0, vector<bool>(4, false)}}, {'D', {0, vector<bool>(4, false)}}, {'C', {0, vector<bool>(4, false)}}};
		int points1 = 0;
		int points2 = 0;
		for (auto i : hand) {
			if (i.at(0) == 'A') {
				points1 += 4;
				points2 += 4;
				suits.at(i.at(1)).second.at(0) = true;
			} else if (i.at(0) == 'K') {
				points1 += 3;
				points2 += 3;
				suits.at(i.at(1)).second.at(1) = true;
			} else if (i.at(0) == 'Q') {
				points1 += 2;
				points2 += 2;
				suits.at(i.at(1)).second.at(2) = true;
			} else if (i.at(0) == 'J') {
				points1++;
				points2++;
				suits.at(i.at(1)).second.at(3) = true;
			}
			suits.at(i.at(1)).first++;
		}
		
		char csuit = 'S';
		int stop = 0;
		for (auto i : suits) {
			if (i.second.second.at(1) && i.second.first == 1) {
				points1--;
				points2--;
			}
			if (i.second.second.at(2) && i.second.first <= 2) {
				points1--;
				points2--;
			}
			if (i.second.second.at(3) && i.second.first <= 3) {
				points1--;
				points2--;
			}
			if (i.second.first == 2) {
				points1++;
			} else if (i.second.first <= 1) {
				points1 += 2;
			}
			
			if (i.second.first > suits.at(csuit).first) {
				csuit = i.first;
			} else if (i.second.first == suits.at(csuit).first) {
				if (i.first == 'S') {
					csuit = 'S';
				} else if (i.first == 'H' && csuit != 'S') {
					csuit = 'H';
				} else if (i.first == 'D' && csuit == 'C') {
					csuit = 'D';
				}
			}
			
			if (i.second.second.at(0)) {
				stop++;
			} else if (i.second.second.at(1) && i.second.first > 1) {
				stop++;
			} else if (i.second.second.at(2) && i.second.first > 2) {
				stop++;
			}
		}
		
		if (points2 >= 16 && stop == 4) {
			cout << "BID NO-TRUMP\n";
		} else if (points1 < 14) {
			cout << "PASS\n";
		} else {
			cout << "BID " << csuit << "\n";
		}
	}
	
	return 0;
}