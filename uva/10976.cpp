#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int k;
	while (cin >> k) {
		vi px;
		vi py;
		for (int y=k+1; y<=2*k; y++) {
			if ((k*y)%(y-k) == 0 && (k*y)/(y-k) >= y) {
				px.push_back((k*y)/(y-k));
				py.push_back(y);
			}
		}
		cout << px.size() << "\n";
		for (int i=0; i<px.size(); i++) {
			cout << "1/" << k << " = 1/" << px[i] << " + 1/" << py[i] << "\n";
		}
	}
	
	return 0;
}