#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void printAnagram(string prefix, string word, string original) {
	if (word.length() == 1 && prefix+word != original) {
		cout << prefix << word << endl;
	} else {
		for (char letter : word) {
			string newPrefix = prefix + letter;
			string rest = word;
			rest.erase(find(rest.begin(), rest.end(), letter));
			printAnagram(newPrefix, rest, original);
		}
	}
}

int main() {
	string input;
	cin >> input;
	printAnagram("", input, input);
	
	return 0;
}