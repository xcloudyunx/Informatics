#include <bits/stdc++.h>

using namespace std;

int main() {
	string command;
	cin >> command;
	
	priority_queue<int> q;
	
	while (command != "done") {
		int num;
		cin >> num;
		
		if (command == "add") {
			q.push(num);
		} else {
			while (num-- > 0 && !q.empty()) {
				cout << q.top() << " ";
				q.pop();
			}
			cout << "\n";
		}
		
		cin >> command;
	}
	
	return 0;
}