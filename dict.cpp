#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<string> words;
	
	for (int i=0; i<N; i++) {
		string S;
		cin >> S;
		words.push_back(S);
	}
	
	sort(words.begin(), words.end());
	
	for (string s : words) {
		cout << s << endl;
	}
	
	return 0;
}