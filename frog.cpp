#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
	int n, k, l, r, f;
	cin >> n >> k;
	vi h(n);
	for (int i=0; i<n; i++) cin >> h[i];
	
	vi next(n, -1);
	queue<int> q;
	for (int i=0; i<n; i++) {
		if (next[i] == -1) q.push(i);
		f = i;
		while (!q.empty()) {
			l = f+1;
			r = f-1;
			while ((l < n && )
			if (q.size() 
		}
	}
	
	return 0;
}