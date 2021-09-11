#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

pair<vi, int> rec(int N, int T, int t, vi tracks, vi output, int sum) {
	if (t == T) return {output, sum};
	auto p1 = rec(N, T, t+1, tracks, output, sum);
	if (sum+tracks[t] <= N) {
		output.push_back(tracks[t]);
		sum += tracks[t];
		auto p2 = rec(N, T, t+1, tracks, output, sum);
		if (p2.second > p1.second || (p2.second == p1.second && p2.first.size() > p1.first.size())) p1 = p2;
	}
	return p1;
}

int main() {
	int N, T;
	while (cin >> N) {
		cin >> T;
		vi tracks(T);
		for (int i=0; i<T; i++) cin >> tracks[i];
		
		auto ans = rec(N, T, 0, tracks, {}, 0);
		for (auto i : ans.first) cout << i << " ";
		cout << "sum:" << ans.second << "\n";
	}
	
	return 0;
}