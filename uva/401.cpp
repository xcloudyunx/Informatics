#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	bool palindrome, mirrored;
	unordered_map<char, char> mirror = {{'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'}, {'8', '8'}};
	while (cin >> s) {
		palindrome = true;
		mirrored = true;
		for (int i=0; i<s.size()/2+1; i++) {
			if (s.at(i) != s.at(s.size()-1-i)) {
				palindrome = false;
			}
			if (mirror.find(s.at(i)) == mirror.end() || mirror.at(s.at(i)) != s.at(s.size()-1-i)) {
				mirrored = false;
			}
			if (!palindrome && !mirrored) {
				break;
			}
		}
		if (palindrome && mirrored) {
			cout << s << " -- is a mirrored palindrome.\n\n";
		} else if (palindrome) {
			cout << s << " -- is a regular palindrome.\n\n";
		} else if (mirrored) {
			cout << s << " -- is a mirrored string.\n\n";
		} else {
			cout << s << " -- is not a palindrome.\n\n";
		}
	}
	
	return 0;
}