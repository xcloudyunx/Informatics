#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int i, j;
	bool palindrome;
	unordered_set<char> punc = {'.', ',', '!', '?', ' '};
	getline(cin, s);
	while (s != "DONE") {
		i = 0;
		j = s.size()-1;
		palindrome = true;
		while (i < j) {
			while (punc.find(s.at(i)) != punc.end()) {
				i++;
				if (i == s.size()) break;
			}
			while (punc.find(s.at(j)) != punc.end()) {
				j--;
				if (j == -1) break;
			}
			if (i >= j) break;
			if (tolower(s.at(i)) != tolower(s.at(j))) {
				palindrome = false;
				break;
			}
			i++;
			j--;
		}
		if (palindrome) {
			cout << "You won't be eaten!\n";
		} else {
			cout << "Uh oh..\n";
		}
		
		getline(cin, s);
	}
	
	return 0;
}