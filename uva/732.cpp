#include <bits/stdc++.h>

using namespace std;

void rec(string s1, string s2, string command, stack<char> s, set<string> &output, int x, int count) {
	s.push(s1.at(x++));
	command += "i ";
	if (x != s1.size()) {
		rec(s1, s2, command, s, output, x, count);
	}
	while (!s.empty() && s.top() == s2.at(count++)) {
		s.pop();
		command += "o ";
		if (x != s1.size()) {
			rec(s1, s2, command, s, output, x, count);
		}
	}
	if (s.empty() && x == s1.size()) {
		command.pop_back();
		output.insert(command);
	}
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		set<string> output;
		stack<char> s;
		rec(s1, s2, "", s, output, 0, 0);
		cout << "[\n";
		for (auto i : output) {
			cout << i << "\n";
		}
		cout << "]\n";
	}
	
	return 0;
}

https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=673&mosmsg=Submission+received+with+ID+24369268

UVa 00732 - Anagram by Stack * (use stack to simulate the process)
