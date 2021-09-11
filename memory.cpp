#include <bits/stdc++.h>

using namespace std;

int main() {
	int F, U;
	cin >> F >> U;
	
	vector< pair<int, int> > free(F);
	vector< pair<int, int> > used(U);
	
	for (int i=0; i<F; i++) {
		cin >> free.at(i).first >> free.at(i).second;
	}
	
	for (int i=0; i<U; i++) {
		cin >> used.at(i).first >> used.at(i).second;
	}
	
	int Q;
	cin >> Q;
	
	for (int i=0; i<Q; i++) {
		int x;
		cin >> x;
	}
	
	return 0;
}