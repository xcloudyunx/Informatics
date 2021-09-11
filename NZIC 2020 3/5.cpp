#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	string N;
	cin >> N;
	
	for (int i=1; i<N.size(); i++) {
		if (i < 1) i = 1;
		if (N[i-1] == N[i]) {
			if (N[i] != '9') {
				N[i]++;
				if (i+1 < N.size()) {
					N[i+1] = '0';
				}
			}
			else {
				i -= 3;
				if (i+1 >= 0) N[i+1]++;
			}
			for (int j=i+2; j<N.size(); j++) {
				N[j] = '0';
			}
		}
		if (i < 0) i = 0;
	}
	
	if (N[0] == '0') cout << "1";
	cout << N;
	
	return 0;
}