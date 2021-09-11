#include <bits/stdc++.h>

using namespace std;

int main() {	
	int N;
	unsigned long long K;
	cin >> N >> K;
	
	vector<unsigned long long> val;
	
	vector<unsigned long long> sum(N+1);
	sum.at(0) = 0;
	
	for (int i=0; i<N; i++) {
		int a;
		cin >> a;
		sum.at(i+1) = sum.at(i)+a;
		
		for (int j=0; j<=i; j++) {
			val.push_back(sum.at(i+1) - sum.at(j));
		}
	}
	
	sort(val.rbegin(), val.rend());
	
	cout << val[K-1] << endl;
	
	return 0;
}