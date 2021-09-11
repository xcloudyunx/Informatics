#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	map<char, int> m = {{'A',0}, {'B',1}, {'C',2}, {'D',3}, {'E',4}, {'F',5}, {'G',6}, {'H',7}, {'I',8}, {'J',9}, {'K',10}, {'L',11}, {'M',12}, {'N',13}, {'O',14}, {'P',15}, {'Q',16}, {'R',17}, {'S',18}, {'T',19}, {'U',20}, {'V',21}, {'W',22}, {'X',23}, {'Y',24}, {'Z',25}};
	
	char current = 'A';
	int total = 0;
	
	for (auto i : s) {
		total += min(abs(m.at(current)-m.at(i)), 26-abs(m.at(current)-m.at(i)))+1;
		current = i;
	}
	
	cout << total;
	
	return 0;
}