#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	ifstream infile;
	infile.open("berries.in");
	ofstream outfile;
	outfile.open("berries.out");
	
	int N, K;
	infile >> N >> K;
	vi B(N);
	for (int i=0; i<N; i++) infile >> B[i];
	
	int low = -1, high = 1001, mid, x;
	while (high-low > 1) {
		mid = (low+high)/2;
		x = 0;
		for (auto i : B) {
			x += i/mid;
		}
		if (x > K) low = mid;
		else high = mid;
	}
	
	x = 0;
	for (auto i : B) {
		x += i/high;
	}
	
	int total = 0, r, n, e, o, y;
	priority_queue<int> q;
	priority_queue<int, vi, greater<int> > other;
	for (auto &i : B) {
		if (i/high > 0) {
			for (int j=0; j<n; j++) {
				total += high;
				q.push(high);
			}
			i -= n*high;
		} else if (x < K) {
			other.push(i); 
		}
	}
	
	while (other.size() > K-x) other.pop();
	while (!other.empty()) {
		total += other.top();
		q.push(other.top());
		other.pop();
		x++;
	}
	while (q.size() > x-K/2) {
		total -= q.top();
		q.pop();
	}
	
	outfile << total << "\n";
	
	infile.close();
	outfile.close();
	return 0;
}