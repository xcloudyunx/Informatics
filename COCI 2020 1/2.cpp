#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long x) {
	if (x < 2) {
		return false;
	}
	for (long long i=2; i<=pow(x, 0.5); i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long A, B;
	cin >> A >> B;
	
	vector<long long> options = {A, B};
	if (A != 2 and B != 2) {
		options.push_back(2);
	}
	
	if (isPrime(A-2)) {
		options.push_back(A-2);
	}
	if (isPrime(A+2)) {
		options.push_back(A+2);
	}
	if (isPrime(B-2)) {
		options.push_back(B-2);
	}
	if (isPrime(B+2)) {
		options.push_back(B+2);
	}
	
	vector< vector<int> > adj(options.size());
	
	for (int i=0; i<options.size(); i++) {
		for (int j=i+1; j<options.size(); j++) {
			if (isPrime(abs(options.at(i)-options.at(j)))) {
				adj.at(i).push_back(j);
				adj.at(j).push_back(i);
			}
		}
	}
	
	vector<int> prev(options.size(), INT_MAX);
	queue<int> q;
	q.push(0);
	prev.at(0) = 0;
	
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		
		for (int i : adj.at(f)) {
			if (prev.at(i) == INT_MAX && isPrime(abs(options.at(f)-options.at(i)))) {
				prev.at(i) = f;
				q.push(i);
			}
		}
	}
	
	if (prev.at(1) == INT_MAX) {
		cout << -1;
	} else {
		stack<long long> s;
		int x = 1;
		while (x != 0) {
			s.push(options.at(x));
			x = prev.at(x);
		}
		s.push(A);
		cout << s.size() << "\n";
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
	}
	
	return 0;
}