#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

vector<ll> sum(100001, 0);

int main() {
	ifstream infile;
	infile.open("race.in");
	ofstream outfile;
	outfile.open("race.out");
	
	for (int i=1; i<100002; i++) sum[i] = sum[i-1]+i;
	
	int K, N, X, t, d, v;
	infile >> K >> N;
	while (N--) {
		infile >> X;
		if (sum[X] <= (K+sum[X]-X)/2) {
			t = X+1;
			v = X;
			d = sum[X];
			while (d < K-X) {
				if (d+2*(v+1) < K) v++;
				t++;
				d += v;
				if (d >= K-X) break;
				t++;
				d += v;
			}
		} else {
			int low = -1, high = 100002;
			while (high-low > 1) {
				int mid = (low+high)/2;
				if (sum[mid] < (K+sum[mid]-mid)/2) low = mid;
				else high = mid;
			}
			t = high+1;
			v = high;
			d = sum[high];
			while (d < K-X) {
				if (d+2*(v+1) < K) v++;
				t++;
				d += v;
				if (d >= K-X) break;
				t++;
				d += v;
			}
		}
		outfile << t << "\n";
	}
	
	return 0;
}