#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int z=1; z<=T; z++) {
		int N, P;
		cin >> N >> P;
		
		vector<int> S(N);
		
		for (int i=0; i<N; i++) {
			cin >> S.at(i);
		}
		
		sort(S.begin(), S.end());
		
		int total = 0;
		
		for (int i=0; i<P-1; i++) {
			total += S.at(P-1)-S.at(i);
		}
		
		int cmin = total;
		
		for (int i=P; i<N; i++) {
			total -= S.at(i-1)-S.at(i-P);
			total += (P-1)*(S.at(i)-S.at(i-1));
			cmin = min(cmin, total);
		}
		
		cout << "Case #" << z << ": " << cmin << endl;
	}
	
	return 0;
}