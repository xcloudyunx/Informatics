#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, K, cscore = 0;
	ii tmp;
	cin >> N >> K;
	vi A(N);
	vi B(N);
	for (int i=0; i<N; i++) cin >> A[i];
	for (int i=0; i<N; i++) cin >> B[i];
	
	cscore += A[0] + B[0];
	priority_queue<ii> aq;
	priority_queue<ii> bq;
	
	aq.push({A[0],0});
	bq.push({B[0],0});
	aq.push({-INF, INF});
	bq.push({-INF, INF});
	
	vi amax(N);
	vi bmax(N);
	amax[0] = A[0];
	bmax[0] = B[0];
	
	for (int i=1; i<N; i++) {
		while (aq.top().second < i-K) aq.pop();
		while (bq.top().second < i-K) bq.pop();
		
		while (aq.top().second == i-K) {
			tmp = aq.top();
			aq.pop();
			while (aq.top().second < i-K) aq.pop();
		}
		amax[i] = max(aq.top().first, bq.top().first)+A[i];
		if (i != N-1) aq.push({amax[i], i});
		
		while (bq.top().second == i-K) {
			bq.pop();
			while (bq.top().second < i-K) bq.pop();
		}
		bmax[i] = max(aq.top().first, bq.top().first)+B[i];
		if (i >= K) {
			bmax[i] = max(bmax[i], tmp.first+B[i-K]+B[i]);
		}
		bq.push({bmax[i], i});
	}
	
	cout << max(amax[N-1]+B[N-1], bmax[N-1]+A[N-1]) << "\n";
	
	for (auto i : amax) cout << i << " ";
	cout << endl;
	for (auto i : bmax) cout << i << " ";
	cout << endl;
	
	return 0;
}