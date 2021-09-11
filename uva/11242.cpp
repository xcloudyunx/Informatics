#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int f, r;
	float cmax;
	cin >> f;
	while (f) {
		cin >> r;
		vi front(f);
		vi rear(r);
		for (int i=0; i<f; i++) cin >> front[i];
		for (int i=0; i<r; i++) cin >> rear[i];
		
		vector<float> d;
		for (auto i : front) {
			for (auto j : rear) {
				d.push_back(j/(float)i);
			}
		}
		
		sort(d.begin(), d.end());
		
		cmax = 0;
		for (int i=1; i<d.size(); i++) {
			cmax = max(cmax, d[i]/d[i-1]);
		}
		
		printf("%.2f\n", cmax);
		
		cin >> f;
	}
	
	return 0;
}