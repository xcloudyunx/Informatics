#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, count;
	cin >> N;
	
	while (N) {
		vector<int> trains(N);
		cin >> trains.at(0);
		while (trains.at(0)) {
			for (int i=1; i<N; i++) {
				cin >> trains.at(i);
			}
			
			stack<int> s;
			count = 0;
			for (int i=1; i<=N; i++) {
				s.push(i);
				while (!s.empty() && s.top() == trains.at(count)) {
					s.pop();
					count++;
				} 
			}

			if (s.empty()) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
			
			cin >> trains.at(0);
		}
		
		cout << "\n";
		cin >> N;
	}
	
	return 0;
}