#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	ifstream infile;
	infile.open("loan.in");
	ofstream outfile;
	outfile.open("loan.out");
	
	ll N, K, M;
	infile >> N >> K >> M;
	
	ll low = 0, high = N/M+1, mid, l, h, m, Y, G;
	while (high-low > 1) {
		mid = (low+high)/2;
		l = -1, h = K+1;
		while (h-l > 1) {
			m = (l+h)/2;
			Y = (N/mid) * pow((mid-1.0f)/mid, m-1);
			if (Y > M) l = m;
			else h = m;
		}
		G = (N/mid) * ((1-pow((mid-1.0f)/mid, l))/(1-(mid-1.0f)/mid));
		G += (K-l)*M;
		if (G < N) high = mid;
		else low = mid;
	}
	
	outfile << low << "\n";
	
	infile.close();
	outfile.close();
	return 0;
}