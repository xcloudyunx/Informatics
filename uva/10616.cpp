#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
	int N, Q, D, M;
	cin >> N >> Q;
	for (int TC=1; N && Q; TC++) {
		vi num(N);
		for (int i=0; i<N; i++) cin >> num[i];
		cout << "SET " << TC << ":\n";
		for (int q=1; q<=Q; q++) {
			cin >> D >> M;
			vector< vector< vector<ll> > > dp(N+1, vector< vector<ll> >(D, vector<ll>(M+1, 0)));
			for (int i=0; i<N; i++) { for (int j=0; j<=i; j++) dp[i+1][(D+num[j]%D)%D][1]++; }
			for (int i=1; i<=N; i++) {
				for (int j=0; j<D; j++) {
					for (int k=2; k<=M; k++) {
						dp[i][j][k] = dp[i-1][(D+(j-num[i-1]%D))%D][k-1] + dp[i-1][j][k];
					}
				}
			}
			
			cout << "QUERY " << q << ": " << dp[N][0][M] << "\n";
		}
		
		cin >> N >> Q;
	}
	
	return 0;
}