#include <bits/stdc++.h>

using namespace std;

int main() {
	int round, num, guess;
	string s, g;
	bool broken;
	cin >> round;
	while (round != -1) {
		cin >> s >> g;
		unordered_map<char, bool> alpha = {{'a', false}, {'b', false}, {'c', false}, {'d', false}, {'e', false}, {'f', false}, {'g', false}, {'h', false}, {'i', false}, {'j', false}, {'k', false}, {'l', false}, {'m', false}, {'n', false}, {'o', false}, {'p', false}, {'q', false}, {'r', false}, {'s', false}, {'t', false}, {'u', false}, {'v', false}, {'w', false}, {'x', false}, {'y', false}, {'z', false}};
		unordered_map<char, bool> guessed = {{'a', false}, {'b', false}, {'c', false}, {'d', false}, {'e', false}, {'f', false}, {'g', false}, {'h', false}, {'i', false}, {'j', false}, {'k', false}, {'l', false}, {'m', false}, {'n', false}, {'o', false}, {'p', false}, {'q', false}, {'r', false}, {'s', false}, {'t', false}, {'u', false}, {'v', false}, {'w', false}, {'x', false}, {'y', false}, {'z', false}};
		num = 0;
		for (auto i : s) {
			if (!alpha.at(i)) {
				num++;
			}
			alpha.at(i) = true;
		}
		guess = 0;
		cout << "Round " << round << "\nYou ";
		broken = false;
		for (auto i : g) {
			if (alpha.at(i)) {
				guessed.at(i) = true;
				num--;
				alpha.at(i) = false;
				if (num == 0) {
					cout << "win.\n";
					broken = true;
					break;
				}
			} else if (!guessed.at(i)) {
				guessed.at(i) = true;
				guess++;
				if (guess == 7) {
					cout << "lose.\n";
					broken = true;
					break;
				}
			}
		}
		
		if (!broken) {
			cout << "chickened out.\n";
		}
		
		cin >> round;
	}
	
	return 0;
}