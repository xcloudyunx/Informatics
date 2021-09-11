#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, n, a, b, c, d;
	bool broken;
	string::size_type it, it2;
	cin >> N >> n;
	
	while (N || n) {
		a = 0, b = 0, c = 0, d = 0;
		
		vector<string> sN(N);
		for (int i=0; i<N; i++) {
			cin >> sN.at(i);
		}
		vector<string> sna(n);
		vector<string> snb(n);
		vector<string> snc(n);
		vector<string> snd(n);
		for (int i=0; i<n; i++) {
			cin >> sna.at(i);
			snb.at(i).resize(n);
			snc.at(i).resize(n);
			snd.at(i).resize(n);
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				snb.at(j).at(n-1-i) = sna.at(i).at(j);
				snc.at(n-1-i).at(n-1-j) = sna.at(i).at(j);
				snd.at(n-1-j).at(i) = sna.at(i).at(j);
			}
		}
		
		for (int i=0; i<N; i++) {
			it = sN.at(i).find(sna.at(0));
			while (it != string::npos) {
				broken = false;
				for (int j=1; j<n; j++) {
					if (i+j >= N) {
						broken = true;
						break;
					}
					it2 =  sN.at(i+j).find(sna.at(j));
					while (it2 < it) {
						it2 = sN.at(i+j).find(sna.at(j), it2+1);
					}
					if (it != it2) {
						broken = true;
						break;
					}
				}
				if (!broken) {
					a++;
				}
				if (it+1 >= N) break;
				it = sN.at(i).find(sna.at(0), it+1);
			}
			
			it = sN.at(i).find(snb.at(0));
			while (it != string::npos) {
				broken = false;
				for (int j=1; j<n; j++) {
					if (i+j >= N) {
						broken = true;
						break;
					}
					it2 =  sN.at(i+j).find(snb.at(j));
					while (it2 < it) {
						it2 = sN.at(i+j).find(snb.at(j), it2+1);
					}
					if (it != it2) {
						broken = true;
						break;
					}
				}
				if (!broken) {
					b++;
				}
				if (it+1 >= N) break;
				it = sN.at(i).find(snb.at(0), it+1);
			}
			
			it = sN.at(i).find(snc.at(0));
			while (it != string::npos) {
				broken = false;
				for (int j=1; j<n; j++) {
					if (i+j >= N) {
						broken = true;
						break;
					}
					it2 =  sN.at(i+j).find(snc.at(j));
					while (it2 < it) {
						it2 = sN.at(i+j).find(snc.at(j), it2+1);
					}
					if (it != it2) {
						broken = true;
						break;
					}
				}
				if (!broken) {
					c++;
				}
				if (it+1 >= N) break;
				it = sN.at(i).find(snc.at(0), it+1);
			}
			
			it = sN.at(i).find(snd.at(0));
			while (it != string::npos) {
				broken = false;
				for (int j=1; j<n; j++) {
					if (i+j >= N) {
						broken = true;
						break;
					}
					it2 =  sN.at(i+j).find(snd.at(j));
					while (it2 < it) {
						it2 = sN.at(i+j).find(snd.at(j), it2+1);
					}
					if (it != it2) {
						broken = true;
						break;
					}
				}
				if (!broken) {
					d++;
				}
				if (it+1 >= N) break;
				it = sN.at(i).find(snd.at(0), it+1);
			}
		}
		
		cout << a << " " << b << " " << c << " " << d << "\n";
		
		cin >> N >> n;
	}
	
	return 0;
}