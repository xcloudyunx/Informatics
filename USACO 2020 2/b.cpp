#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	ifstream infile;
	infile.open("photo.in");
	
	int N, total = 0, bt = 0, r, ctrue = 0, x;
	bool broken;
	infile >> N;
	
	for (int i=1; i<=N; i++) total += i;
	
	vector<int> b(N-1);
	for (int i=0; i<N-1; i++) { infile >> b[i]; bt += b[i]; }
	
	infile.close();
	
	r = 2*total-bt;
	vector<int> used(N+1, 0);
	vector<int> output(N);
	
	for (int i=1; i<r; i++) {
		if (r-i > N) continue;
		ctrue++;
		broken = false;
		used[i] = ctrue, used[r-i] = ctrue;
		output[0] = i, output[N-1] = r-i;
		for (int j=0; j<N-2; j++) {
			x = b[j]-output[j];
			if (x < 1 || x > N || used[x] == ctrue) {
				broken = true;
				break;
			}
			used[x] = ctrue;
			output[j+1] = x;
		}
		if (!broken) break;
	}
	
	
	ofstream outfile;
	outfile.open("photo.out");
	
	for (int i=0; i<N; i++) {
		if (i) outfile << " ";
		outfile << output[i];
	}
	outfile << "\n";
	
	outfile.close();
	
	return 0;
}