#include <bits/stdc++.h>

using namespace std;

int main() {
	long long P;
	cin >> P;
	
	unordered_set<long long> v;
	
	long long guessR = (4*P)/3;
	long long size = guessR;
	long long rootR;

	while (true) {
		rootR = sqrt(guessR);
		
		long long ctotal = 0;
		
		for (long long x=0; x<=rootR; x++) {
			ctotal += sqrt(guessR-x*x)+1;
		}
		
		if (ctotal == P) {
			if (v.find(guessR-1) == v.end()) {
				size = 1;
				guessR--;
			} else {
				cout << guessR << endl;
				break;
			}
			v.insert(guessR);
		} else if (size == 1) {
			if (ctotal < P) {
				if (v.find(guessR+1) == v.end()) {
					guessR += size;
				} else {
					cout << guessR+1 << endl;
					break;
				}
			} else {
				if (v.find(guessR-1) == v.end()) {
					guessR -= size;
				} else {
					cout << guessR << endl;
					break;
				}
			}
			v.insert(guessR);
		} else {
			size /= 2;
			if (ctotal < P) {
				guessR += size;
			} else {
				guessR -= size;
			}
		}
	}
	
	return 0;
}