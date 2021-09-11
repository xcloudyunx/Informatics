#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, T, num = 0;
	ll total = 0;
	cin >> N;
	vii Z(N);
	priority_queue<ii> q;
	for (int i=0; i<N; i++) {
		cin >> T >> Z[i].first;
		total += T;
		q.push({Z[i].first, i});
	}
	for (int i=0; total>0; i++) {
		total -= q.top().first;
		if (total >= 0) Z[q.top().second].second = q.top().first;
		else Z[q.top().second].second = q.top().first+total;
		q.pop();
		num++;
	}
	
	cout << N-num << "\n";
	for (int i=0; i<N; i++) {
		if (i) cout << " ";
		cout << Z[i].second;
	}
	
	return 0;
}